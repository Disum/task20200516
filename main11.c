#include <stdio.h>
#include <time.h>
#include "solve11.h"
#include "f.h"

int main(int argc, char **argv)
{
	double a, eps, r, res = 0;
	int k;
	clock_t time;

	if( argc!=4 || sscanf(argv[1], "%lf", &a)!=1 || sscanf(argv[2], "%lf", &eps)!=1 || eps<=0 || sscanf(argv[3], "%d", &k)!=1 || k<0 || k>6)
	{
		fprintf(stderr, "Usage: %s a eps k\t( eps>0, 0<=k<=6 )\n", argv[0]);
		return -1;
	}

	time = clock();

	switch( k )
	{
		case 0:
			res = solve11(&f0, a, eps, &r);
			break;
		case 1:
			res = solve11(&f1, a, eps, &r);
			break;
		case 2:
			res = solve11(&f2, a, eps, &r);
			break;
		case 3:
			res = solve11(&f3, a, eps, &r);
			break;
		case 4:
			res = solve11(&f4, a, eps, &r);
			break;
		case 5:
			res = solve11(&f5, a, eps, &r);
			break;
		case 6:
			res = solve11(&f6, a, eps, &r);
	}

	if( res>0 )
		printf("Answer = %.16e\tb = %.16e\tf() calls = %d\tElapsed = %.2lf sec\n", r, res, get_count_f(), ( (double)(clock() - time) )/CLOCKS_PER_SEC);
	else
		printf("Answer = no_answer\tb = %.16e\tf() calls = %d\tElapsed = %.2lf sec\n", res, get_count_f(), ( (double)(clock() - time) )/CLOCKS_PER_SEC);

	return 0;
}
