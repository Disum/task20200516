#include <math.h>
#include "solve10.h"
#include "solve08.h"
#define N 1e7

double solve10(double (*f)(double), double a, double eps, double *r)
{
	double b = a, h, s = 0, i;
	int res;

	for( h = 1; h<N; h *= 2 )
	{
		b = a + h;

		res = solve08(f, a, b, eps, &i);
		if( res<0 )
			return -1;
		s += i;

		if( fabs(i)<eps )
		{
				*r = s;
				return b;
		}

		a = b;
	}

	return -1;
}
