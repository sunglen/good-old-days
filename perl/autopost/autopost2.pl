#!/usr/bin/perl
#autopost1: autopost article in a bbs2www based bbs system.version 2.
#use libwww-perl.
#Not Yet complete.--this version cannot work if the text contain '&'
use LWP::UserAgent;
use HTTP::Request;
use HTTP::Response;
use URI;

$host="127.0.0.1";

#login
$account='userid=sunge&passwd=!L0ve';
$ua=new LWP::UserAgent;
$req=new HTTP::Request;
$req->method('POST');
$req->url('http://'.$host.'/cgi-bin/bbslog');
$req->content_type('application/x-www-form-urlencoded');
$req->content($account);

$res=$ua->request($req);

@list=split(/\r?\n/,$res->as_string);
foreach(@list){
        if(/^[Ll]ocation:/){
                $_=~ s/^[Ll]ocation:.*\?//g;
                $secret=$_;
                last;
        }
}                                                                                                             
print "your secret is $secret";
$board="notepad";
$article=$ARGV[0]; #attention! [0]
open(ARTICLE,"<$article") || die "cannot open $article\n";
chop($title=<ARTICLE>);
while(<ARTICLE>){
	$text .= $_;
}
#post article
$body="board=$board".'&'.$secret.'&'."title=$title".'&'.'exchange=Y&signature=1'.'&'."text=$text";
$u=new URI $body;
print $u->as_string;
$req->method('POST');
$req->url('http://'.$host.'/cgi-bin/bbssnd');
$req->content_type('application/x-www-form-urlencoded');
$req->content($u->as_string);
$res=$ua->request($req);
print $res->as_string;
print $req
#logout
#&HTTP_get($host,$port,"http://$host/cgi-bin/bbsout?".'&'.$secret);
# 
