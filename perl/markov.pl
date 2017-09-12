#!/usr/bin/perl
#markov.pl: markov chain algorithm for 2-word prefixes.

$MAXGEN=10000;
$NONWORD="\n";
$w1=$w2=$NONWORD;
while(<>){
	foreach(split){
		push(@{$statetable{$w1."".$w2}},$_);
		#Programming Perl: 
		#or: @{$statetable{$w1."".$w2}}=(@{$statetable{$w1."".$w2}},$_);
		($w1,$w2)=($w2,$_);
	}
}
push(@{$statetable{$w1."".$w2}},$NONWORD);

$w1=$w2=$NONWORD;
for($i=0;$i<$MAXGEN;$i++){
	$suf=$statetable{$w1.$w2};
	$r=int(rand @$suf);
	$t=$suf->[$r]; # or $t=$$suf[$r];
	exit if($t eq $NONWORD);
	print "$t\n";
	($w1,$w2)=($w2,$t);
}


