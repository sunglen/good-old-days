#!/usr/bin/perl
#jargon: find the define of the WORD in jargon file.
$jargonfile="</home/downloadTexts/jargonfile/jarg431";
open(FILE,$jargonfile);
$word=$ARGV[0];
while(<FILE>){
	if(/^\:$word\:+ /i){
		$found=1;
	}elsif(/^\:.+\:+ /i){
		$found=0;
	}
	if($found==1){
		print;
	}
}
close(FILE);

