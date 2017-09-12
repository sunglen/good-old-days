#http_post.pl: send POST and rcv response.(RFC1945)
#require chat2.pl

require 'chat2.pl';
sub HTTP_post
{
	# one would call: &HTTP_post("www.xxx.com",80,uri,header,body);
	local($host,$port,$uri,$request_headers,$request_body)=@_;
	
	if(!&chat'open_port($host,$port)){
		print $!;
	}

	&chat'print("POST $uri HTTP/1.0\r\n");
	
	&chat'print($request_headers);
	
	#send CR LF line to indicate the end of the header.
	&chat'print("\r\n");
	
	&chat'print($request_body);
	
	while(length($tmp=&chat'expect(5,'(.|\n)+','$&'))){
		$response .= $tmp;
	}

	if($response =~ /\r?\n\r?\n/){
		($response_headers,$response_body)=split(/\r?\n\r?\n/,$response);
	}else{ 
		$response_headers="";
		$response_body=$response;
	}

	($response_headers,$response_body);
}

