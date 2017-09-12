#!/usr/bin/perl
#autopost3: autopost article in a bbs2www based bbs system. version 3.
#use libwww-perl.
use LWP::UserAgent;
use HTTP::Request::Common;
use HTTP::Response;
use URI;

$host="127.0.0.1";

#login
print STDERR "connect to $host,login...";
$userid='sunge';
$passwd='!L0ve';
$ua=new LWP::UserAgent;
$req=POST 'http://'.$host.'/cgi-bin/bbslog',
	[userid => $userid,
	 passwd => $passwd,
	];

$res=$ua->request($req);
if($res->is_redirect){
	print STDERR "success.\n";
	@list=split(/\r?\n/,$res->as_string);
	foreach(@list){
        	if(/^[Ll]ocation:/){
                	$_=~ s/^[Ll]ocation:.*\?//g;
                	$secret=$_;
                	last;
        	}
	}                                                                                                             @secret=split(/&|=/,$secret);
}else{
	print STDERR $res->as_string;
	print STDERR "failed.\n";
	exit 1;
}
#post article

#Why the flowing code not work?
#$secret=~s/&/,
#/g;
#$secret=~s/=/ => /g;
#print $secret;
$board="notepad";
$article=$ARGV[0]; #attention! [0]
print STDERR "Try to post $article in $board...";
open(ARTICLE,"<$article") || die "cannot open $article\n";
chop($title=<ARTICLE>);
while(<ARTICLE>){
	$text .= $_;
}
close(ARTICLE);
$exchange='Y';
$nsignature='1';
$req=POST 'http://'.$host.'/cgi-bin/bbssnd',
	[board => $board,
	 $secret[0] => $secret[1],
	 $secret[2] => $secret[3],
	 $secret[4] => $secret[5],
#	 $secret,
	 title => $title,
	 exchange => $exchange,
	 signature => $nsignature,
	 text => $text,
	];
$res=$ua->request($req);
if($res>is_success){
	print STDERR "succeed.\n";
}else{
	print STDERR "failed.\n";
}

#logout
$req=GET 'http://'.$host.'/cgi-bin/bbsout?'.$secret; 
$res=$ua->request($req);
if($res->is_success){
	print STDERR "logout successfully.\n";
}else{
	print STDERR "logout failed.\n";
}

exit 0;
