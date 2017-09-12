#!/usr/bin/perl
open(FD,"list");
while($key=<FD>)
{
 $count{$key}=$count{$key}+1;
}
@list=sort(keys(%count));
for($i=0;$i<@list;$i++)
{
 print "$list[$i]\n";
 print "$count{$list[$i]}\n";
}
