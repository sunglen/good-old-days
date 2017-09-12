#spline.m: 3-degree spline interpolation.
#usage: y=spline(x0,y0,x);
function y=spline(x0,y0,x)
	n=length(x0)-1; m=length(x);

	for i=1:n
		h(i)=x0(i+1)-x0(i-1+1);
		f(i)=(y0(i+1)-y0(i-1+1))/h(i);
	endfor

	for i=1:(n-1)
		na(i)=h(i+1)/(h(i)+h(i+1));
		u(i)=1-na(i);
		g(i+1)=3*(u(i)*f(i+1)+na(i)*f(i));
	endfor
	g(0+1)=3*f(1);
	g(n+1)=3*f(n);
	A=2*eye(n+1)+diag([na;1],-1)+diag([1;u],1);

	M=A^-1*g;
	for j=1:m
		for i=1:n
			if(x(j)>=x0(i-1+1) && x(j)<=x0(i+1))
				break;
			endif
		endfor

		y(1,j)=(x(j)-x0(i+1))^2*(h(i)+2*(x(j)-x0(i-1+1)))/h(i)^3*y0(i-1+1) + \
			(x(j)-x0(i-1+1))^2*(h(i)+2*(x0(i+1)-x(j)))/h(i)^3*y0(i+1) + \
			(x(j)-x0(i+1))^2*(x(j)-x0(i-1+1))/h(i)^3*M(i-1+1) + \
			(x(j)-x0(i-1+1))^2*(x(j)-x0(i+1))/h(i)^3*M(i+1);
	endfor

endfunction
