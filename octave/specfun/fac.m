#fac.m: return the factorial of int n.
#usage: m=fac(n)

function m = fac (n)
	if(nargin!=1)
		usage("m=fac(n)");	
	elseif(n==1 || n==0)
		m=n;
	else
		m=1;
		for i=2:n
			m=i.*m;
		endfor
	endif
endfunction

