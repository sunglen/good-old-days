#!/usr/bin/perl
use LWP::UserAgent;
use HTTP::Request::Common;
use HTTP::Response;
use URI;
use HTTP::Cookies;

$ua=new LWP::UserAgent;
$cookie_jar=HTTP::Cookies->new(file => "lwpcookies.txt", autosave => 1, ignore_discard => 1);
$ua->cookie_jar($cookie_jar);
$host="127.0.0.1";

print STDERR "connect to $host and ...\n";
$userid='sunge';
$passwd='!L0ve';
$req=POST 'http://'.$host.'/cgi-bin/sndcookie.pl';
	[userid => $userid,
	 passwd => $passwd,
	];

$res=$ua->request($req);
print "now the cookie_jar has :\n", $cookie_jar->as_string(); 
print "\n\n";
print STDERR $res->as_string;
