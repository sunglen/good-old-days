#http_get.pl: send GET and rcv response.
#require chat2.pl

require 'chat2.pl';
sub HTTP_get
{
	# one would call: &HTTP_get("www.xxx.com",80,"path");
	local($host,$port,$path)=@_;
	
	if(!&chat'open_port($host,$port)){
		print $!;
	}

	&chat'print("GET $path HTTP/1.0\r\n");
	
	#send CR LF line to indicate the end of the request.(RFC1945)
	&chat'print("\r\n");
	
	while(length($tmp=&chat'expect(5,'(.|\n)+','$&'))){
		$response .= $tmp;
	}

	if($response =~ /\r?\n\r?\n/){
		($headers,$document)=split(/\r?\n\r?\n/,$response);
	}else{ 
		$headers="";
		$document=$response;
	}

	($headers,$document);
}

