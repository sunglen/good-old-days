#!/usr/bin/perl
%words=("fred","camel","barney","llama","betty","oyster","wilma","oyster");
print "What is your name?";
$name=<STDIN>;
chop($name);
if($name =~ /^randal\b/i){
   print "Hello,$name!How good of you to be here!\n";
   }else{print "Hello,$name!\n";
         $secretword=$words{$name}; #获取保密字 .
         if($secretword eq ""){
         $secretword="groucho";#为什么是duck?
         }
         print "What is the secret word?";
         $guess=<STDIN>;
         chop($guess);
         while($guess ne $secretword){
         print "Wrong,try again.What is the secret word?";
         $guess=<STDIN>;
         chop($guess);
         }
   }


