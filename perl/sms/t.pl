while(<>){
	$res=$res.$_;
    }
@list=split(/\r?\n/,$res);

foreach(@list){
    if(/alert/){
	$_ =~ s/^.+alert\(\'(.+)\'\).+$/$1/g;
	print $error=$_;
	last;
    }
}

