#include "solve04.h"

double solve04(double (*f)(double), double a, double b, int n)
{
	double h = (b - a)/n, res = f(a)/2;
	int i;

	for( i = 1; i<n; i++ )
		res += f(a + i*h);

	res += f(b)/2;
	res *= h;

	return res;
}
