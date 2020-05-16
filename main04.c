#include <stdio.h>
#include <time.h>
#include "solve04.h"
#include "f.h"

int main(int argc, char **argv)
{
	double a, b, res;
	int n, k;
	clock_t time;

	if( argc!=5 || sscanf(argv[1], "%lf", &a)!=1 || sscanf(argv[2], "%lf", &b)!=1 || a>=b || sscanf(argv[3], "%d", &n)!=1 || n<1 || sscanf(argv[4], "%d", &k)!=1 || k<0 || k>6)
	{
		fprintf(stderr, "Usage: %s a b n k\t( a<b, n>=1, 0<=k<=6 )\n", argv[0]);
		return -1;
	}

	time = clock();

	switch( k )
	{
		case 0:
			res = solve04(&f0, a, b, n);
			break;
		case 1:
			res = solve04(&f1, a, b, n);
			break;
		case 2:
			res = solve04(&f2, a, b, n);
			break;
		case 3:
			res = solve04(&f3, a, b, n);
			break;
		case 4:
			res = solve04(&f4, a, b, n);
			break;
		case 5:
			res = solve04(&f5, a, b, n);
			break;
		case 6:
			res = solve04(&f6, a, b, n);
	}

	printf("Answer = %.16e\tf() calls = %d\tElapsed = %.2lf sec\n", res, get_count_f(), ( (double)(clock() - time) )/CLOCKS_PER_SEC);

	return 0;
}
