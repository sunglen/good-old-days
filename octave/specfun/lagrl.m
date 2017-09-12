#lagrl.m: lagrl interpoltion.
#usage: y=lagrl(x0,y0,x);
function y=lagrl(x0,y0,x)
	n=length(x0)-1;
	for i=0:n
		for j=n:-1:0
			X(i+1,n-j+1)=x0(i+1)^j;
		endfor
	endfor
	pn=X^-1*y0';
	y=polyval(pn,x);
endfunction
