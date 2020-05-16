#include <stdio.h>
#include <time.h>
#include "solve09.h"
#include "f.h"

int main(int argc, char **argv)
{
	double a, b, eps, r;
	int k, res = 0;
	clock_t time;

	if( argc!=5 || sscanf(argv[1], "%lf", &a)!=1 || sscanf(argv[2], "%lf", &b)!=1 || a>=b || sscanf(argv[3], "%lf", &eps)!=1 || eps<=0 || sscanf(argv[4], "%d", &k)!=1 || k<0 || k>6)
	{
		fprintf(stderr, "Usage: %s a b eps k\t( a<b, eps>0, 0<=k<=6 )\n", argv[0]);
		return -1;
	}

	time = clock();

	switch( k )
	{
		case 0:
			res = solve09(&f0, a, b, eps, &r);
			break;
		case 1:
			res = solve09(&f1, a, b, eps, &r);
			break;
		case 2:
			res = solve09(&f2, a, b, eps, &r);
			break;
		case 3:
			res = solve09(&f3, a, b, eps, &r);
			break;
		case 4:
			res = solve09(&f4, a, b, eps, &r);
			break;
		case 5:
			res = solve09(&f5, a, b, eps, &r);
			break;
		case 6:
			res = solve09(&f6, a, b, eps, &r);
	}

	if( res>0 )
		printf("Answer = %.16e\tn = %d\tf() calls = %d\t\tElapsed = %.2lf sec\n", r, res, get_count_f(), ( (double)(clock() - time) )/CLOCKS_PER_SEC);
	else
		printf("Answer = no_answer\tn = %d\tf() calls = %d\tElapsed = %.2lf sec\n", res, get_count_f(), ( (double)(clock() - time) )/CLOCKS_PER_SEC);

	return 0;
}
