#include "solve03.h"

double solve03(double (*f)(double), double x, double h)
{
	return (f(x + h) -  2*f(x) + f(x - h))/(h*h);
}
