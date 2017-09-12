#spline-phototype.
function y=spline_phototype(x0,y0,x)
	n=length(x0)-1; m=length(x);
	X=zeros(4*n);
	Y=zeros(4*n,1);
	for i=0:n
		if(i==0)
			for j=0:3
				X(4*i+1,j+1)=x0(i+1)^(3-j);
			endfor
			Y(4*i+1)=y0(i+1);
			X(4*i+2,1)=6*x0(i+1)^2; X(4*i+2,2)=2;
		elseif(i>0 && i<n)
			for j=0:3
				X(4*i-1,4*(i-1)+j+1)=x0(i+1)^(3-j);
				X(4*i,4*i+j+1)=x0(i+1)^(3-j);

			endfor
			Y(4*i-1)=y0(i+1);
			Y(4*i)=y0(i+1);	
			X(4*i+1,4*(i-1)+1)=-3*x0(i+1)^2;
			X(4*i+1,4*(i-1)+2)=-2*x0(i+1);
			X(4*i+1,4*(i-1)+3)=-1;
			X(4*i+1,4*(i-1)+5)=3*x0(i+1)^2;
			X(4*i+1,4*(i-1)+6)=2*x0(i+1);
			X(4*i+1,4*(i-1)+7)=1;
			X(4*i+2,4*(i-1)+1)=-6*x0(i+1);
			X(4*i+2,4*(i-1)+2)=-2;
			X(4*i+2,4*(i-1)+5)=6*x0(i+1);
			X(4*i+2,4*(i-1)+6)=2;
		else
			for j=0:3
				X(4*i-1,4*(i-1)+j+1)=x0(i+1)^(3-j);
			endfor
			Y(4*i-1)=y0(i+1);
			X(4*i,4*(n-1)+1)=6*x0(i+1);
			X(4*i,4*(n-1)+2)=2;
		endif
	endfor
	A=X^-1*Y;
	for i=1:n
		for j=0:3
			a(i,j+1)=A(4*i-(3-j));
		endfor
	endfor
	for i=1:m
		for j=0:(n-1)
			if(x(i)>=x0(j+1) && x(i)<=x0(j+2))
				k=j+1;
				break;
			endif
		endfor
		y(1,i)=polyval([a(k,1),a(k,2),a(k,3),a(k,4)],x(i));
	endfor
endfunction

