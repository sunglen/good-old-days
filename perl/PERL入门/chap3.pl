#!/usr/bin/perl
open(FD,"list");
$max=$number=@wordlist=<FD>;
for($i=1;$i<=$number/2;$i++)
{
     ($wordlist[$max-$number],$wordlist[$number-1])=($wordlist[$number-1],$wordlist[$max-$number]);
     $number-=1;
}
print(@wordlist);
%sunge=("abc","sunge","abc","petrel");
print($sunge{"abc"});

