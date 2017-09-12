#!/usr/bin/perl
#autopost4: autopost article in a bbs2www based bbs system. version 4.
#use libwww-perl.
use LWP::UserAgent;
use HTTP::Request::Common;
use HTTP::Response;
use URI;

$ua=new LWP::UserAgent;
$host="127.0.0.1";

#login
print STDERR "connect to $host and login...";
$userid='sunge';
$passwd='!L0ve';
$req=POST 'http://'.$host.'/cgi-bin/bbslog',
	[userid => $userid,
	 passwd => $passwd,
	];

$res=$ua->request($req);
if($res->is_redirect){
	print STDERR "ok.\n";
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

while($board=<*>){
	if(-d $board){
		chdir($board);
		while($article=<*>){
			if($article!~/\.posted$/){
				print STDERR "Try to post $article in $board...";
				open(ARTICLE,"<$article") || die "cannot open $article\n";
				chop($title=<ARTICLE>);
				$text='';
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
					 title => $title,
					 exchange => $exchange,
					 signature => $nsignature,
					 text => $text,
					];
				$res=$ua->request($req);
				if($res->is_redirect){
					print STDERR "succeed.\n";
					rename($article,$article.'.posted');
				}else{
					print STDERR "failed.\n";
				}

			}
		}
		chdir('..');
	}
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
