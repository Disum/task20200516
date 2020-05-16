#include <math.h>
#include "solve07.h"
#define sign(x) ((x)<0 ? (-1) : 1)

double solve07(double (*f)(double), double a, double b, int n)
{
	/* val[0] = x[i]
	 * val[1] = f(x[i])
	 * val[2] = fabs(x[i])
	 * val[3] = sqrt( fabs(x[i]) );
	 * val[4] = sqrt( fabs(x[i]) )*sign(x[i])
	 * val[5] = fabs(x[i])*sqrt( fabs(x[i]) )
	 * val[6] = fabs(x[i])*fabs(x[i])*sqrt( fabs(x[i]) )*sign(x[i])
	 * val[7] = ( f(x[i + 1]) - f(x[i]) )/( x[i + 1] - x[i] )
	 * */
	double res = 0, h = (b - a)/(2*n), div_diff, val_fir[8], val_sec[2], val_thi[8], *p_val_fir = val_fir, *p_val_thi = val_thi, *buff;
	int i;

	p_val_fir[0] = a;
	p_val_fir[1] = f(a);
	p_val_fir[2] = fabs(a);
	p_val_fir[3] = sqrt( p_val_fir[2] );
	p_val_fir[4] = p_val_fir[3]*sign(a);
	p_val_fir[5] = p_val_fir[2]*p_val_fir[3];
	p_val_fir[6] = p_val_fir[2]*p_val_fir[2]*p_val_fir[4];

	val_sec[0] = a - h;

	p_val_thi[0] = a - 2*h;

	for( i = 0; i<n; i++ )
	{
		val_sec[0] += 2*h;
		val_sec[1] = f( val_sec[0] );

		p_val_thi[0] += 4*h;
		p_val_thi[1] = f( p_val_thi[0] );
		p_val_thi[2] = fabs( p_val_thi[0] );
		p_val_thi[3] = sqrt( p_val_thi[2] );
		p_val_thi[4] = p_val_thi[3]*sign( p_val_thi[0] );
		p_val_thi[5] = p_val_thi[2]*p_val_thi[3];
		p_val_thi[6] = p_val_thi[2]*p_val_thi[2]*p_val_thi[4];

		p_val_fir[7] = ( val_sec[1] - p_val_fir[1] )/h;
		div_diff = ( ( p_val_thi[1] - val_sec[1] )/h - p_val_fir[7] )/(2*h);

		res += ( p_val_fir[1] - p_val_fir[0]*p_val_fir[7] + div_diff*p_val_fir[0]*val_sec[0] )*( p_val_thi[4] - p_val_fir[4] )*2 + ( p_val_fir[7] - div_diff*(p_val_fir[0] + val_sec[0]) )*( p_val_thi[5] - p_val_fir[5])*2/3 + div_diff*(p_val_thi[6] - p_val_fir[6])*2/5;

		buff = p_val_fir;
		p_val_fir = p_val_thi;
		p_val_thi = buff;
	}

	return res;
}
