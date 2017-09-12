#!/usr/bin/perl
#$Id: sms.pl,v 1.2 2003/11/02 15:34:28 sunge Exp $
#sms.pl: 利用http://www.zexiao.com/sms/index.asp
#提供的sms服务来发送短消息。经测试该sms服务能发送到神州行手机。
#use libwww-perl.
use LWP::UserAgent;
use HTTP::Request::Common;
use HTTP::Response;
use URI;
use HTTP::Cookies;

$ua=new LWP::UserAgent;
$cookie_jar=HTTP::Cookies->new(file => "~/lwpcookies.txt", autosave => 1, ignore_discard => 1);
$ua->cookie_jar($cookie_jar);

#读入命令行参数。
for($i=0; $i<=$#ARGV; $i++){
    if($ARGV[$i] eq "-n"){
	$mobile_number=$ARGV[$i+1];
    }elsif($ARGV[$i] eq "-f"){
	$message_file=$ARGV[$i+1];
    }elsif($ARGV[$i] eq "-t"){
	$send_times=$ARGV[$i+1];
    }
}
if($mobile_number eq "" || $message_file eq ""){
    print STDERR "usage: $0 -n mobile_number -f message_file [-t send_times]\n";
    exit;
}
if($send_times==""){
    $send_times=1;
}

$main_url='http://www.zexiao.com/sms/index.asp';
$name="孙舸";
$cf=1;

open(MESSAGE,"<$message_file") || die "cannot open $message_file\n";
$text='';
while(<MESSAGE>){
    $text .= $_;
}
close(MESSAGE);

$req_p=POST $main_url,
    [mobil => $mobile_number,
     name => $name,
     cf => $cf,
     message => $text,
     xcni => "发 送",
     ]; 

for($i=1; $i<=$send_times; $i++){
    $moved_url='';
    #post:
    $res=$ua->request($req_p);
    if($res->is_error){
	print STDERR "Error: request post error.\n";
	exit;
    }elsif(!$res->is_redirect){
	@list=split(/\r?\n/,$res->as_string);
	foreach(@list){
	    if(/alert/){
		$_ =~ s/^.+alert\(\'(.+)\'\).+$/$1/g;
		$error=$_;
		last;
	    }
	}
	print STDERR "Error: $error.\n";
	exit;
    }

    #Object moved and get:

    @list=split(/\r?\n/,$res->as_string);
    foreach(@list){
        if(/^[Ll]ocation:/){
	    $_ =~ s/^[Ll]ocation: *//g;
	    $moved_url=$_;
	    last;
        }
    }
	
    $req_g = HTTP::Request->new(GET => $moved_url);
    $res = $ua->request($req_g);
    if ($res->is_success){
	print STDERR "send message success! times: $i.\n";
    }else{
#	print STDERR $res->as_string;
	print STDERR "Error: ".$res->status_line."\n";
	exit;
    }
}
