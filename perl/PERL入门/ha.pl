#!/usr/bin/perl

open(FD,"list");
while($name=<FD>)
{
chop($name);
$word=<FD>;
chop($word);
$words{$name}=$word;
write;
}
close(FD);
$name="孙舸";
print "$words{$name}\n";
$name="江海燕";
print "$words{$name}\n";
#open(MAIL,"|mail root");
#print MAIL "ok: 我爱江海燕\n";
#close(MAIL);
#@passwd=getpwuid($<);
#$name=$passwd[6];
#$name=~s/,.*//;
#print "$name\n";
#print "$passwd[2]\n";
$filename=<*list>;
print "$filename\n";
dbmopen(%words,"dblist",0666);

format STDOUT=
@<<<<<<<<<<<<<<<<<<<<@<<<<<<<<<<<<<<<<<<<
$name,$words{$name}
.
format STDOUT_TOP=
第@<<页
$%

姓名                 电话号码

.









