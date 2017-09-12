#!/usr/bin/perl
#sample_get_client.pl

require "http_get.pl";

($hostname,$port,$url)=@ARGV;

($headers,$body)=&HTTP_get($hostname,$port,$url);

print "\n";

if($headers){
	print "headers:\n";
	print "------------------\n";
	print $headers;
	print "\n";
}else{
	print "no headers.\n";
}
print "\n";
if($body){
	print "body:\n";
	print "------------------\n";
	print $body;
	print "\n";
}else{
	print "no body.\n";
}

