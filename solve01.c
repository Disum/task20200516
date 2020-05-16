#include "solve01.h"

double solve01(double (*f)(double), double x, double h)
{
	return (f(x + h) - f(x))/h;
}
