#!/usr/bin/perl
while(<>)
{
$sunge[$i]=$_;
$i++;
}
$count=$i=@sunge;
for($i;$i>=$count/2+1;$i--)
{
   ($sunge[$i],$sunge[$count-$i])=($sunge[$count-$i],$sunge[$i]);
}
print(@sunge);




