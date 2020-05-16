#include <math.h>
#include "solve06.h"
#define sign(x) ((x)<0 ? (-1) : 1)

double solve06(double (*f)(double), double a, double b, int n)
{
	/* val[0] = x[i]
	 * val[1] = f(x[i])
	 * val[2] = fabs(x[i])
	 * val[3] = sqrt( fabs(x[i]) );
	 * val[4] = sqrt( fabs(x[i]) )*sign(x[i])
	 * val[5] = fabs(x[i])*sqrt( fabs(x[i]) )
	 * */
	double res = 0, h = (b - a)/n, div_diff, val_fir[6], val_sec[6], *p_val_fir = val_fir, *p_val_sec = val_sec, *buff;
	int i;

	p_val_fir[0] = a;
	p_val_fir[1] = f(a);
	p_val_fir[2] = fabs(a);
	p_val_fir[3] = sqrt( p_val_fir[2] );
	p_val_fir[4] = p_val_fir[3]*sign(a);
	p_val_fir[5] = p_val_fir[2]*p_val_fir[3];

	p_val_sec[0] = a + h;

	for( i = 0; i<n; i++ )
	{
		p_val_sec[0] += 2*h;
		p_val_sec[1] = f( p_val_sec[0] );
		p_val_sec[2] = fabs( p_val_sec[0] );
		p_val_sec[3] = sqrt( p_val_sec[2] );
		p_val_sec[4] = p_val_sec[3]*sign( p_val_sec[0] );
		p_val_sec[5] = p_val_sec[2]*p_val_sec[3];
		div_diff = ( p_val_sec[1] - p_val_fir[1] )/h;

		res += ( p_val_fir[1] - p_val_fir[0]*div_diff )*( p_val_sec[4] - p_val_fir[4] )*2 + div_diff*( p_val_sec[5] - p_val_fir[5])*2/3;

		buff = p_val_fir;
		p_val_fir = p_val_sec;
		p_val_sec = buff;
	}

	return res;
}
