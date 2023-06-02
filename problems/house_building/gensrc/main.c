#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int get_rand(int lower, int upper)
{
	return (rand() % (upper - lower + 1)) + lower;
}

void same_grid(FILE* f, int n, int m, int k)
{
	int	i;
	int	j;

	fprintf(f, "%d %d %d\n", n, m, k);
	for (i = 0; i < n; i++) {
		if (i != 0) {
			fprintf(f, "\n");
		}
		for (j = 0; j < m; j++) {
			if (j != 0) {
				fprintf(f, " ");
			}
			fprintf(f, "%d", 1);
		}
	}
}

void rand_grid(FILE* f, int n, int m, int k)
{
	int	i;
	int	j;

	fprintf(f, "%d %d %d\n", n, m, k);
	for (i = 0; i < n; i++) {
		if (i != 0) {
			fprintf(f, "\n");
		}
		for (j = 0; j < m; j++) {
			if (j != 0) {
				fprintf(f, " ");
			}
			fprintf(f, "%d", get_rand(0, 100));
		}
	}
}

int main(int argc, char* argv[])
{
	FILE*	fptr;
	int	i;
	char	path[] = "data/x.in";

	for (i = 1; i < 5; i++) {
		path[5] = i + '0';
		fptr = fopen(path, "w");
		if (fptr == NULL) {
			printf("Error!");
			return 1;
		}

		fprintf(fptr, "%d\n", i);
		switch (i) {
			case 1:
				same_grid(fptr, 100, 100, 1000);
				break;
			case 2:
				rand_grid(fptr, 100, 100, 500);
				break;
			case 3:
				rand_grid(fptr, 200, 1, 30);
				break;
			default:
				rand_grid(fptr, 1000, 1000, 40000);

		}
		fclose(fptr);
	}
	return 0;
}

