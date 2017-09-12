#!/usr/bin/perl
#blank: add unpaddable blank to a translated man pages.
while(<>){
	tr/\015//d;
	unless(/^\.\w+/ or /^$/){
		s/ /\\ /g;
		s/$/\\/;
	}
	print;
}

