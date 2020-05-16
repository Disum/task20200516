#include <math.h>
#include "solve08.h"
#define N 1e7

int solve08(double (*f)(double), double a, double b, double eps, double *r)
{
	int n, i;
	double h = b - a, fa = f(a), fb = f(b), sum1, sum2;

	sum1 = h*fa/2 + h*fb/2;
	h /= 2;
	for( n = 1; n<N; n *= 2 )
	{
		for( i = 0, sum2 = 0; i<n; i++ )
			sum2 += f(a + (2*i + 1)*h);
		sum2 = h*sum2 + sum1/2;

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
