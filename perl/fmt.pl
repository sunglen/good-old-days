#!/usr/bin/perl
$nwords=12;
while(<>){ chop; print "$_ ";  if($i==$nwords){ print "\n"; $i=0; } $i++; }
print "\n";
