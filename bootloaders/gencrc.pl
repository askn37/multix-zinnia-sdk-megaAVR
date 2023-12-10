#!/usr/bin/env perl
=comment=
/**
 * @file gencrc.pl
 * @author askn (K.Sato) multix.jp
 * @brief Tool to calculate and export CRC.
 * @version 0.1
 * @date 2023-12-06
 *
 * @copyright Copyright (c) 2023 askn37 at github.com
 *
 */
=cut
use strict;
use warnings;
use Getopt::Std;
use IO::File;
use Data::Dumper;
my $max_limit = 128;  # KiB
my $usage = <<__EOL__;

Usage: gencrc.pl [OPTIONS]

  -i <file>   Input binary file. (Required)
              Can read up to ${max_limit}KiB.
  -o <file>   Output binary file. : Default is not used
    -F        Output file even if CRC matches.

  -c <num>    CRC algorithm select: Default value = 1
                1 CRC-16/MCRF4XX(CCITT) P=0x8408 (Reverse 0x1021)
                2 CRC-16/CCITT(FALSE) P=0x1021 (Bigendian)
                3 CRC-16/XMODEM P=0x1021 (Bigendian, Initialize=0)
                4 CRC-32/JAMCRC P=0xedb88320 (Reverse 0x04c11db7)
                5 CRC-32/MPEG-2 P=0x04c11db7 (Bigendian)
                6 CRC-32/IEEE802.3 P=0xedb88320 (Reverse 0x04c11db7, Xout)
                7 CRC-32/BZIP2 P=0x04c11db7 (Bigendian, Xout)
                8 CRC-32/POSIX P=0x04c11db7 (Big, Init=0, Fini=-1, Xout)
  -t          Delete consecutive `0xff` at the end of the input file.
              This may corrupt legitimate data.
  -a          Adjust the alignment to store the CRC.
              `0xff` is inserted in the gap.
              Used silently if `-t` is used.

  -u          Use Unwinding-CRC calculation result mode.
              It has the following sub-options:
    -p <num>  Page size granularity:
                1 256 byte page
                2 512 byte page : Default value
                4 1024 byte page
    -b <num>  Assume that the specified border page number is padded
              with `0xff` at the end.
              It is limited to ${max_limit}KiB or less.
              If not specified, the minimum value will be calculated.
    -x        Pad the output file with 0xff to page boundaries.

  -h          Print this usage.
  -q          Quiet report.

    If no output file is created and the CRC
    matches the specified conditions, exit=0.

__EOL__

# Option specification
getopts('aFhqutxb:c:i:o:s:p:', \my %args);
my $trim      = $args{t};
my $adjust    = $trim // $args{a};
my $unwind    = $args{u};
my $expand    = defined $args{u} ? $args{x} : undef;
my $force_out = $args{F};
my $infile    = $args{i};
my $outfile   = $args{o};
my $p_border  = $args{b} // 1;
my $crc_type  = $args{c} // 1;
my $page_size = ${{1=>256,2=>512,4=>1024}}{$args{p} // 2};
my $crc_prod  = ${{
  1 => {
    # This model is compatible with AVR-LIBC's _crc_ccitt_update()
    name       => "CRC-16/MCRF4XX(CCITT)"
  , alignment  => 2
  , endian     => 0
  , mask       => 0xffff
  , initialize => 0xffff
  , polynomial => 0x8408
  , finalize   => 0
  , xor        => 0
  , unwinding  => 0x0811  # (P << 1) | 1
  , encoder    => \&encoder_crc16_ror
  , decoder    => \&decoder_crc16_ror
  }
, 2 => {
    # This model is the same as AVR-LIBC's _crc_xmodem_update,
    # but the initial value is different.
    # Use this if you want to enable CRC16 with AVR's FUSE_SYCFG0 and CRCSCAN.
    name       => "CRC-16/CCITT(FALSE)"
  , alignment  => 2
  , endian     => 1
  , mask       => 0xffff
  , initialize => 0xffff
  , polynomial => 0x1021
  , finalize   => 0
  , xor        => 0
  , unwinding  => 0x8810  # (P >> 1) | 0x8000
  , encoder    => \&encoder_crc16_rol
  , decoder    => \&decoder_crc16_rol
  }
, 3 => {
    # This model is compatible with AVR-LIBC's _crc_xmodem_update()
    name       => "CRC-16/XMODEM"
  , alignment  => 2
  , endian     => 1
  , mask       => 0xffff
  , initialize => 0
  , polynomial => 0x1021
  , finalize   => 0
  , xor        => 0
  , unwinding  => 0x8810  # (P >> 1) | 0x8000
  , encoder    => \&encoder_crc16_rol
  , decoder    => \&decoder_crc16_rol
  }
, 4 => {
    # Verification of common CRC32 streams.
    name       => "CRC-32/JAMCRC"
  , alignment  => 4
  , endian     => 0
  , mask       => 0xffffffff
  , initialize => 0xffffffff
  , polynomial => 0xedb88320
  , finalize   => 0
  , xor        => 0
  , unwinding  => 0xdb710641  # (P << 1) | 1
  , encoder    => \&encoder_crc32_ror
  , decoder    => \&decoder_crc32_ror
  }
, 5 => {
    # CRC-32/JAMCRC endian difference.
    name       => "CRC-32/MPEG-2"
  , alignment  => 4
  , endian     => 1
  , mask       => 0xffffffff
  , initialize => 0xffffffff
  , polynomial => 0x04c11db7
  , finalize   => 0
  , xor        => 0
  , unwinding  => 0x82608edb  # (P >> 1) | 0x80000000
  , encoder    => \&encoder_crc32_rol
  , decoder    => \&decoder_crc32_rol
  }
, 6 => {
    # Ordinary CRC32 XOR output. (IEEE802.3)
    name       => "CRC-32/IEEE802.3"
  , alignment  => 4
  , endian     => 0
  , mask       => 0xffffffff
  , initialize => 0xffffffff
  , polynomial => 0xedb88320
  , finalize   => 0
  , xor        => 0xffffffff
  , unwinding  => 0xdb710641  # (P << 1) | 1
  , encoder    => \&encoder_crc32_ror
  , decoder    => \&decoder_crc32_ror
  }
, 7 => {
    # CRC-32/MPEG-2 XOR output.
    name       => "CRC-32/BZIP2"
  , alignment  => 4
  , endian     => 1
  , mask       => 0xffffffff
  , initialize => 0xffffffff
  , polynomial => 0x04c11db7
  , finalize   => 0
  , xor        => 0xffffffff
  , unwinding  => 0x82608edb  # (P >> 1) | 0x80000000
  , encoder    => \&encoder_crc32_rol
  , decoder    => \&decoder_crc32_rol
  }
, 8 => {
    # Initial value is zero and output is XOR.
    name       => "CRC-32/POSIX"
  , alignment  => 4
  , endian     => 1
  , mask       => 0xffffffff
  , initialize => 0
  , polynomial => 0x04c11db7
  , finalize   => 0xffffffff
  , xor        => 0xffffffff
  , unwinding  => 0x82608edb  # (P >> 1) | 0x80000000
  , encoder    => \&encoder_crc32_rol
  , decoder    => \&decoder_crc32_rol
  }
}}{$crc_type} // {};
my $crc_name   = $crc_prod->{name};
my $alignment  = $crc_prod->{alignment};
my $endian = $crc_prod->{endian} ? "BE" : "LE";
my $format = ${["v","n","V","N"]}[($crc_prod->{endian})|($alignment == 4 ? 2 : 0)];
my($crc, $output, $topend) = (0, 1, 0);

# Conditions for displaying Usage
die $usage if $args{h} || !defined $infile;
unless (-f $infile) { $args{h} = 1; warn "Illegal: -i input file not found.\n"; }
elsif ($max_limit * 1024 < -s $infile) {
  $args{h} = 1; warn "Illegal: -i input file size is too large.\n";
}
unless (defined $crc_name) { $args{h} = 1; warn "Illegal: -c <num>\n"; }
if ($unwind) {
  unless (defined $page_size) { $args{h} = 1; warn "Illegal: -p <num>\n"; }
  elsif ( $p_border < 1 && $max_limit * 1024 < $p_border * $page_size) {
    $args{h} = 1; warn "Illegal: -b <num>\n";
  }
}
die $usage if $args{h};

### CRC generator definition ###

sub encoder {
  my($crc_prod, $buff, $length) = @_;
  my $crc = $crc_prod->{initialize};
  for (my $i = 0; $i < $length; $i++) {
    $crc = $crc_prod->{encoder}->($crc_prod, $crc, vec($buff, $i, 8));
  }
  return $crc;
}
sub decoder {
  my($crc_prod, $topend, $length, $buff) = @_;
  my $over = length $buff;
  my $crc = $crc_prod->{finalize};
  for (my $i = $topend; --$i >= $length; ) {
    $crc = $crc_prod->{decoder}->($crc_prod, $crc,
      $i < $over ? vec($buff, $i, 8) : 0xff);
  }
  return $crc;
}
sub trimmer {
  my($crc_prod, $crc, $topend, $length) = @_;
  for (my $i = $length; $i < $topend; $i++) {
    $crc = $crc_prod->{encoder}->($crc_prod, $crc, 0xff);
  }
  return $crc;
}

### CRC encoder/decoder definition ###

sub encoder_crc16_ror {
  my($crc_prod, $crc, $data) = @_;
  $crc ^= $data;
  for (my $i = 0; $i < 8; $i++) {
    $crc = ($crc >> 1) ^ ($crc_prod->{polynomial} & -($crc & 1));
  }
  return $crc;
}
sub decoder_crc16_ror {
  my($crc_prod, $crc, $data) = @_;
  for (my $i = 0; $i < 8; $i++) {
    $crc = ($crc << 1) ^ ($crc_prod->{unwinding} & -(($crc >> 15) & 1));
  }
  return $crc_prod->{mask} & $crc ^ $data;
}

sub encoder_crc16_rol {
  my($crc_prod, $crc, $data) = @_;
  $crc ^= ($data << 8);
  for (my $i = 0; $i < 8; $i++) {
    $crc = ($crc << 1) ^ ($crc_prod->{polynomial} & -(($crc >> 15) & 1));
  }
  return $crc_prod->{mask} & $crc;
}
sub decoder_crc16_rol {
  my($crc_prod, $crc, $data) = @_;
  for (my $i = 0; $i < 8; $i++) {
    $crc = ($crc >> 1) ^ ($crc_prod->{unwinding} & -($crc & 1));
  }
  return $crc ^ ($data << 8);
}

sub encoder_crc32_ror {
  my($crc_prod, $crc, $data) = @_;
  $crc ^= $data;
  for (my $i = 0; $i < 8; $i++) {
    $crc = ($crc >> 1) ^ ($crc_prod->{polynomial} & -($crc & 1));
  }
  return $crc;
}
sub decoder_crc32_ror {
  my($crc_prod, $crc, $data) = @_;
  for (my $i = 0; $i < 8; $i++) {
    $crc = ($crc << 1) ^ ($crc_prod->{unwinding} & -(($crc >> 31) & 1));
  }
  return $crc_prod->{mask} & $crc ^ $data;
}

sub encoder_crc32_rol {
  my($crc_prod, $crc, $data) = @_;
  $crc ^= ($data << 24);
  for (my $i = 0; $i < 8; $i++) {
    $crc = ($crc << 1) ^ ($crc_prod->{polynomial} & -(($crc >> 31) & 1));
  }
  return $crc_prod->{mask} & $crc;
}
sub decoder_crc32_rol {
  my($crc_prod, $crc, $data) = @_;
  for (my $i = 0; $i < 8; $i++) {
    $crc = ($crc >> 1) ^ ($crc_prod->{unwinding} & -($crc & 1));
  }
  return $crc ^ ($data << 24);
}

### Main processing ###

# Read the input file in binary format
open my $FH, "<", $infile or die "$!\n";
$FH->binmode(1);
my $stream = join '', <$FH>;
$FH->close;
my $length = length $stream;

# Input file overview
unless ($args{q}) {
  printf "Input-file: %s\n", $infile;
  printf "Input-size: %d\n", $length;
  my $crc = encoder($crc_prod, "123456789", 9) ^ $crc_prod->{xor};
  printf "CRC-type: \"%s\" model 0x%0*X\n",
    $crc_name, $alignment * 2, $crc;
}

# Trim trailing invalid 0xff
if ($trim) {
  $stream =~ s{\xff*$}{}go;
  $length = length $stream;
  printf "Trim-after-size: %d\n", $length;
}

# Generate execution
if ($unwind) {
  ### unwind CRC calculation
  my($trim, $fixd, $enti);
  if ($adjust) {
    # alignment adjustment
    $stream .= "\xff" x ($length % $alignment);
    $length = length $stream;
  }
  # Calculate the total number of pages
  my $border_page = int(($length + $page_size - 1) / $page_size);
  $p_border = $border_page if $p_border < $border_page;
  # Overall final address
  $topend = $p_border * $page_size;
  # Calculate the CRC of the code part
  $crc = encoder($crc_prod, $stream, $length);
  if ($crc_prod->{xor}) {
    # Calculate the entire CRC
    $enti = trimmer($crc_prod, $crc, $topend - $alignment, $length);
    if ($enti != ($crc_prod->{finalize} ^ $crc_prod->{xor})) {
      if ((($length + $alignment) % $page_size) <= $alignment) {
        # Add pages if there is no storage space
        $p_border++;
        $topend += $page_size;
        # Re-calculate the entire CRC
        $enti = trimmer($crc_prod, $crc, $topend, $length);
      }
      # Xor the two CRCs from the beginning and end, and then Xor the padding value
      $trim = decoder($crc_prod, $topend - $alignment, $length, $stream);
      $fixd = $crc_prod->{mask} ^ $crc ^ $trim;
    }
    else {
      # The correct CRC is already there
      $length -= $alignment;
      $fixd = unpack $format, substr $stream, $length, $alignment;
      # Recalculation for display only
      # This should be the same value for both
      $crc = encoder($crc_prod, $stream, $length);
      $trim = decoder($crc_prod, $topend, $length, $stream);
      $output = 0;
    }
  }
  else {
    # Calculate the entire CRC
    $enti = trimmer($crc_prod, $crc, $topend, $length);
    if ($enti != $crc_prod->{finalize}) {
      # If the whole CRC does not match, check the CRC storage area
      if ((($length + $alignment) % $page_size) <= $alignment) {
        # Add pages if there is no storage space
        $p_border++;
        $topend += $page_size;
        # Re-calculate the entire CRC
        $enti = trimmer($crc_prod, $crc, $topend, $length);
      }
      # Xor the two CRCs from the beginning and end, and then Xor the padding value
      $trim = decoder($crc_prod, $topend, $length, $stream);
      $fixd = $crc_prod->{mask} ^ $crc ^ $trim;
    }
    else {
      # The correct CRC is already there
      $length -= $alignment;
      $fixd = unpack $format, substr $stream, $length, $alignment;
      # Recalculation for display only
      # This should be the same value for both
      $crc = encoder($crc_prod, $stream, $length);
      $trim = decoder($crc_prod, $topend, $length, $stream);
      $output = 0;
    }
  }
  unless ($args{q}) {
    print  "[Unwind-CRC calculation mode]\n";
    print  "[Xor result]\n" if $crc_prod->{xor};
    printf "Page-size: %d\n", $page_size;
    printf "Page-length:  %d\n", $p_border;
    printf "Page-capacity: \$%06X %.2fKiB\n", $topend, $topend / 1024;
    printf "Entire-CRC%d: %0*X ($endian) %s\n", $alignment * 8, $alignment * 2,
      $enti ^ $crc_prod->{xor}, $output ? "(Oops)" : "(Good)";
    printf "Code-CRC%d: %0*X ($endian)\n", $alignment * 8, $alignment * 2, $crc ^ $crc_prod->{xor};
    printf "Trim-CRC%d: %0*X ($endian)\n", $alignment * 8, $alignment * 2, $trim ^ $crc_prod->{xor};
    printf "Fixed-CRC%d: %0*X ^ %0*X ($endian)\n",
      $alignment * 8, $alignment * 2, $fixd, $alignment * 2, $fixd ^ $crc_prod->{xor};
    printf "Position: \$%06X\n", $length;
  }
  else {
    printf "%0*X\n", $alignment * 2, $enti ^ $crc_prod->{xor};
  }
  $crc = $fixd;
  # If the overall CRC matches, file output is not necessary
}
else {
  ### Normal CRC calculation
  my($enti, $fixd) = (0);
  if ($adjust) {
    # alignment adjustment
    $stream .= "\xff" x ($length % $alignment);
    $length = length $stream;
  }
  if ($crc_prod->{xor}) {
    if ($alignment <= $length) {
      $crc = encoder($crc_prod, $stream, $length - $alignment) ^ $crc_prod->{xor};
      $enti = $crc ^ unpack $format, substr $stream, $length - $alignment, $alignment;
      if (!$force_out && $enti == $crc_prod->{finalize}) {
        $output = 0;
        $length -= $alignment;
      }
    }
    $enti = $crc = encoder($crc_prod, $stream, $length) ^ $crc_prod->{xor};
  }
  else {
    # Find the CRC of the code part
    $enti = $crc = encoder($crc_prod, $stream, $length);
    $output = 0 if $enti == $crc_prod->{finalize};
    # Generate a new CRC
    substr $stream, $length, $alignment, pack $format, $crc_prod->{mask};
    $topend = $length + $alignment;
    $crc = decoder($crc_prod, $topend, $length, $stream) ^ $enti ^ $crc_prod->{mask};
  }
  unless ($args{q}) {
    print  "[Normal-CRC calculation mode]\n";
    print  "[Xor result]\n" if $crc_prod->{xor};
    printf "Entire-CRC%d: %0*X ($endian) %s\n", $alignment * 8, $alignment * 2, $enti, $output ? "(Oops)" : "(Good)";
    printf "Fixed-CRC%d: %0*X ($endian)\n", $alignment * 8, $alignment * 2, $crc;
    printf "Position: \$%06X\n", $length;
  }
  else {
    printf "%0*X\n", $alignment * 2, $crc;
  }
}

# create output file
if ($outfile) {
  unless ($output) {
    print "*** No need to add CRC.\n" unless $args{q};
    exit(0) unless $force_out;
  }
  # stream add CRC
  substr $stream, $length, $alignment, pack $format, $crc;
  if ($expand) {
    # When padding to page boundaries
    $length = length $stream;
    $stream .= "\xff" x ($topend - $stream);
  }
  die "*** Error: output file too large.\n"
    if $max_limit * 1024 < $length;
  unless ($args{q}) {
    printf "Output-file: %s\n", $outfile;
    printf "Output-size: %d\n", $length ; #length $stream;
  }
  open my $FH, ">", $outfile or die "$!\n";
  $FH->binmode(1);
  $FH->print(substr $stream, 0, $length + $alignment);
  $FH->close;
  exit(0);
}
exit($output);

1;
__END__
