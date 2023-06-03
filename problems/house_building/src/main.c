#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int main(int argc, char* argv[])
{
	Grid*	g;
	clock_t	start_ct;
	clock_t	end_ct;
	double	timediff;

	g = get_grid();

	/* Run algorithm */
	start_ct = clock();
	solve(g);
	end_ct = clock();

	timediff = (double) (end_ct - start_ct) / CLOCKS_PER_SEC;
	printf("Time: %.6f (s)\n", timediff);

	free_grid(g);
	return 0;
}

