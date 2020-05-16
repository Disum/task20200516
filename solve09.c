#include <math.h>
#include "solve09.h"
#define N 1e7

int solve09(double (*f)(double), double a, double b, double eps, double *r)
{
	int n, i;
	double h = b - a, simp1, simp2, fa = f(a), fb = f(b), sum1, sum2;

	sum1 = 0;
	simp1 = h*fa/3 + h*f(a + h)*4/3 + h*fb/3;
	h /= 2;
	for( n = 1; n<N; n *= 2 )
	{
		for( i = 0, sum2 = 0; i<n; i++ )
			sum2 += f(a + 2*i*h + h);
		sum2 *= h;
		simp2 = h*fa/3 + sum1*2/3 + sum2*4/3 + h*fb/3;

		if( fabs(simp2 - simp1)<eps )
		{
			*r = simp2;
			return n;
		}

		sum1 = (sum1 + sum2)/2;
		simp1 = simp2;
		h /= 2;
	}

	return -1;
}
