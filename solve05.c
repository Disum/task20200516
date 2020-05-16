#include "solve05.h"

double solve05(double (*f)(double), double a, double b, int n)
{
	double h = (b - a)/(2*n), res = (f(a) + f(b))/2 + 2*f(b - h);
	int i;

	for( i = 1; i<n; i++ )
		res += 2*f(a + (2*i - 1)*h) + f(a + 2*i*h);

	res *= h*2/3;

	return res;
}
