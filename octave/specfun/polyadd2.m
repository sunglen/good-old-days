#polyadd2.m: add 2 polynomial
#usage: p=polyadd2(p1,p2);
function p=polyadd2(p1,p2)
	n1=length(p1);n2=length(p2);
	if((n=n1-n2)>0)
		for i=n2:-1:1
			p2(i+n)=p2(i);
		endfor
		for i=1:n
			p2(i)=0;
		endfor
	elseif(n<0)
		m=-n;
		for i=n1:-1:1
			p1(i+m)=p1(i);
		endfor
		for i=1:n
			p1(i)=0;
		endfor
	endif
	p=p1+p2;
endfunction

