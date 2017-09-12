#!/usr/bin/perl
@words=("superman","superdoggy","supergirl");
print "what's your name?";
$name=<STDIN>;
chop($name);
if ($name eq "孙舸") {
    print "Hello,孙舸!How good of you to be here!\n";
}else{
    print "Hello,$name!\n"; #普通欢迎词
    print "what is the secret word?";
    $guess=<STDIN>;
    chop($guess);
     $i=0; #先试试这个单词
     $correct="maybe"; #猜测正确与否
     while($correct eq "maybe"){
          if($words[$i] eq $guess){
           $correct="yes"; #对!
          }elsif($i<2){
           $i=$i+1;#看看下一个单词.
          }else{
           print "Wrong,try again.What is the secret word?";
           $guess=<STDIN>;
           chop($guess);
           $i=0;#重新检查,别忘了.

          }
    }
}

