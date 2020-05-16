#include <math.h>
#include "solve12.h"
#define N 1e7

int solve12(double (*x)(double), double (*y)(double), double a, double b, double eps, double *r)
{
	int n, i;
	double h = b - a, xa = x(a), ya = y(a), xb = x(b),  yb = y(b), sum1, sum2, x1, y1, x2, y2;

	sum1 = 0;
	h /= 2;
	for( n = 1; n<N; n *= 2 )
	{
		sum2 = 0;
		x1 = xa;
		y1 = ya;
		for( i = 0; i<n; i++ )
		{
			x2 = x(a + i*h);
			y2 = y(a + i*h);

			sum2 += sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) );

			x1 = x2;
			y1 = y2;
		}
		sum2 += sqrt( (xb - x2)*(xb - x2) + (yb - y2)*(yb - y2) );

		if( fabs(sum2 - sum1)<eps )
		{
			*r = sum2;
			return n;
		}

		sum1 = sum2;
		h /= 2;
	}

	return -1;
}
