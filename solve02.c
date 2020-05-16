#include "solve02.h"

double solve02(double (*f)(double), double x, double h)
{
	return (f(x + h) - f(x - h))/(2*h);
}
