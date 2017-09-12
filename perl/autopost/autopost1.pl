#!/usr/bin/perl
#autopost1: autopost article in a bbs2www based bbs system.version 1.

require "http_post.pl";
require "http_get.pl";

$host="127.0.0.1";
$port=80;
$header="Content-type:application/x-www-form-urlencoded\r\n"."Content-length:";

#login
$body='userid=sunge&passwd=!L0ve';
$content_length=length($body)."\r\n";
($h,$b)=&HTTP_post($host,$port,"/cgi-bin/bbslog",$header.$content_length,$body);
@list=split(/\r?\n/,$h);
foreach(@list){
	if(/^[Ll]ocation:/){
		$_=~ s/^[Ll]ocation:.*\?//g;
		$secret=$_;
		last;
	}
}

$board="notepad";
$article=$ARGV[0]; #attention! [0]
open(ARTICLE,"<$article") || die "cannot open $article\n";
chop($title=<ARTICLE>);
while(<ARTICLE>){
	$text .= $_;
}

#encode $title and $article.

#end of encode

#post article
$body="board=$board".'&'.$secret.'&'."title=$title".'&'.'exchange=Y&signature=1'.'&'."text=$text";
print $body;
$content_length=length($body)."\r\n";
&HTTP_post($host,$port,"/cgi-bin/bbssnd",$header.$content_length,$body);

#logout
&HTTP_get($host,$port,"http://$host/cgi-bin/bbsout?".'&'.$secret);





