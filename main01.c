#include <stdio.h>
#include <math.h>
#include <time.h>
#include "solve01.h"
#include "f.h"
#define EPS 1e-16

int main(int argc, char **argv)
{
	double x, h, res;
	int k;
	clock_t time;

	if( argc!=4 || sscanf(argv[1], "%lf", &x)!=1 || sscanf(argv[2], "%lf", &h)!=1 || fabs(h)<EPS || sscanf(argv[3], "%d", &k)!=1 || k<0 || k>6 )
	{
		fprintf(stderr, "Usage: %s x h k\t( fabs(h)>=%e, 0<=k<=6 )\n", argv[0], EPS);
		return -1;
	}

	time = clock();

	switch( k )
	{
		case 0:
			res = solve01(&f0, x, h);
			break;
		case 1:
			res = solve01(&f1, x, h);
			break;
		case 2:
			res = solve01(&f2, x, h);
			break;
		case 3:
			res = solve01(&f3, x, h);
			break;
		case 4:
			res = solve01(&f4, x, h);
			break;
		case 5:
			res = solve01(&f5, x, h);
			break;
		case 6:
			res = solve01(&f6, x, h);
	}

	printf("Answer = %e\tf() calls = %d\tElapsed = %.2lf sec\n", res, get_count_f(), ( (double)(clock() - time) )/CLOCKS_PER_SEC);

	return 0;
}
