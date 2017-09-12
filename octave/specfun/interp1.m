#interp1.m: liner interpoltion.
#usage: y=interp1(x0,y0,x);
function y=interp1(x0,y0,x)
	n=length(x0)-1; m=length(x); 
	for i=1:m
		t=x(i);
		for j=0:n
			if(j!=0 && t>=x0(j-1+1) && t<=x0(j+1))
				l(j+1)=(t-x0(j-1+1))/(x0(j+1)-x0(j-1+1));
			elseif(j!=n && t>=x0(j+1) && t<=x0(j+1+1))
				l(j+1)=(t-x0(j+1+1))/(x0(j+1)-x0(j+1+1));
			else
				l(j+1)=0;
			endif
			l(j+1)=l(j+1)*y0(j+1);
		endfor
		y(1,i)=sum(l);
	endfor
endfunction

