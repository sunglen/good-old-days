#!/usr/bin/perl
#find a book named like $name in the book list file: maketitlepage.html 
#this file was downloaded in http://digital.library.upenn.edu/books/
$book_list_file="<maketitlepage.html";
$author_first=0;
open(FILE,$book_list_file);
if($ARGV[0] eq '-t' && $ARGV[2] eq '-a'){
	$title=$ARGV[1];
	$author=$ARGV[3];
}elsif($ARGV[0] eq '-t' && $ARGV[2] eq ''){
	$title=$ARGV[1];
	$author='.*';
}elsif($ARGV[0] eq '-a' && $ARGV[2] eq '-t'){
	$title=$ARGV[3];
	$author=$ARGV[1];
	$author_first=1;
}elsif($ARGV[0] eq '-a' && $ARGV[2] eq ''){
	$title='.*';
	$author=$ARGV[1];
	$author_first=1;
}else{
	print "Usage: findbook -t title -a author\n";
	exit 1;
}
if($title eq '' || $author eq ''){
	print "Usage: Please spec a certain title or author\n"; 
	exit 1;
}

print "<html>
<head>
<title>Find Result</title>
</head>
<body>
<ul>\n";

$pre_line=<FILE>;
while(<FILE>){
	if($author_first == 0 && /^<cite>.*$title.*<\/cite>/i && /<\/A> by $author/i){
		print $pre_line;
		print $_;
	}elsif($author_first == 1 && /<\/A> by $author/i && /^<cite>.*$title.*<\/cite>/i){
		print $pre_line;
		print $_;
	}
	$pre_line=$_;
}

print "</ul>
</body>
</html>";

close(FILE);

