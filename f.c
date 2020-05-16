#include <math.h>
#include "f.h"

static int count_f = 0;

int get_count_f(void)
{
	return count_f;
}

double f0(double x)
{
	++count_f;

	(void)x;

	return 1;
}

double f1(double x)
{
	++count_f;

	return 1 + x;
}

double f2(double x)
{
	++count_f;

	return 1 + x + x*x;
}

double f3(double x)
{
	++count_f;

	return 1 + x + x*x + x*x*x;
}

double f4(double x)
{
	++count_f;

	return 1 + x + x*x + x*x*x + x*x*x*x;
}

double f5(double x)
{
	++count_f;

	return exp(-x);
}

double f6(double x)
{
	++count_f;

	return 1/(25*x*x + 1);
}

static int count_x = 0;

int get_count_x(void)
{
	return count_x;
}

double x(double t)
{
	count_x++;

	return t;
}
