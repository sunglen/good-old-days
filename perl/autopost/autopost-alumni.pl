#!/usr/bin/perl
#autopost-alumni: autopost article in alumni.163.com
#use libwww-perl.
use LWP::UserAgent;
use HTTP::Request::Common;
use HTTP::Response;
use URI;
use HTTP::Cookies;

$ua=new LWP::UserAgent;
$cookie_jar=HTTP::Cookies->new(file => "~/lwpcookies.txt", autosave => 1, ignore_discard => 1);
$ua->cookie_jar($cookie_jar);

@filelist=@ARGV;
$reg_host="reg4.163.com";
$base_url="http://alumni.163.com/alumni/";
$main_url=$base_url."main.jsp?prov=17&schid=28585&clsid=340479&year=1998";
$msgboard_url=$base_url."msgboard.jsp?provid=17&schid=28585&clsid=340479&clsyear=1998";
#login
print STDERR "connect to $reg_host and login...\n";
$userid='solaris0';
$passwd='!L0vePetrel';
$alumni_url='http://alumni.163.com/alumni/index.jsp';
$req=POST 'http://'.$reg_host.'/CheckUser.jsp',
	[username => $userid,
	 password => $passwd,
	 url => $alumni_url,
	];

$res=$ua->request($req);
$res->is_error && die "connect failed!\n";
#for debug:
#print STDERR $res->as_string;
@list=split(/\r?\n/,$res->as_string); #"?" match 0 to 1 times, instead of {0,1}
foreach(@list){
       	if(/HTTP-EQUIV=REFRESH.*URL=http:\/\/alumni.163.com\/alumni\/index.j/){
		print STDERR "login ok.\n";
		$login_ok=1;
		last;
       	}
}
$login_ok == 1 || die "login failed.\n";
#get index.jsp
$req = HTTP::Request->new(GET => $alumni_url."?username=solaris0");
$res = $ua->request($req);
if ($res->is_success) {
	#print $res->content;
	print STDERR "index.jsp got.\n";
} else {
	print STDERR "Error: " . $res->status_line . "\n";
        }
#get main.jsp
$req = HTTP::Request->new(GET => $main_url);
$res = $ua->request($req);
if ($res->is_success) {
	#print $res->content;
	print STDERR "main.jsp got.\n";
} else {
	print STDERR "Error: " . $res->status_line . "\n";
        }
#get msgboard.jsp
$req = HTTP::Request->new(GET => $msgboard_url);
$res = $ua->request($req);
if ($res->is_success) {
	#print $res->content;
	print STDERR "msgboard.jsp got.\n";
} else {
	print STDERR "Error: " . $res->status_line . "\n";
}
#post article
$school='28585';
$class='340479';
$province='17';
$year='1998';
foreach $article (@filelist){
	print STDERR "Try to post $article ...";
	open(ARTICLE,"<$article") || die "cannot open $article\n";
	$text='';
	while(<ARTICLE>){
		$text .= $_;
	}
	close(ARTICLE);
	$req=POST $base_url.'backaction/addmsg.jsp',
		[content => $text,
		 schid => $school,
		 clsid => $class,
		 provid => $province,
		 clsyear => $year,
		 startpos => '0',
		];
	$res=$ua->request($req);
	if($res->is_redirect){
		print STDERR "post succeed.\n";
		#print STDERR $res->as_string;

	}else{
		print STDERR $res->as_string;
		print STDERR "post failed.\n";
             }
}
#print the msgboard.
$msgboard_url='/alumni/msgboard.jsp?schid=28585&clsid=340479&provid=17&clsyear=1998&startpos=0';
@list=split(/\r?\n/,$res->as_string);
foreach(@list){
	if(/^[Ll]ocation:/){
		$_=~ s/^[Ll]ocation: *//g;
		$msgboard_url=$_;
		last;
	}
}
$req = HTTP::Request->new(GET => 'http://alumni.163.com'.$msgboard_url);
$res = $ua->request($req);
if ($res->is_success) {
	print STDERR "get new message.\n";
	print $res->content;
} else {
	print STDERR "Error: " . $res->status_line . "\n";
        }
exit 0;

