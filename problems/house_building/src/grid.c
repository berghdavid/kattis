#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include "grid.h"

void print_grid(Grid* g)
{
	int	i;
	int	j;

	printf("Test: %d\n", g->t);
	printf("Rows: %d\n", g->n);
	printf("Cols: %d\n", g->m);
	printf("Persons: %d\n", g->k);

	printf("+");
	for (i = 0; i < 4 * g->m + 1; i++) {
		printf("-");
	}
	printf("+\n");

	for (i = 0; i < g->n; i++) {
		printf("| ");
		for (j = 0; j < g->m; j++) {
			printf("%.3d ", g->grid[i][j]);
		}
		printf("|\n");
	}

	printf("+");
	for (i = 0; i < 4 * g->m + 1; i++) {
		printf("-");
	}
	printf("+\n");
}

int read_dig()
{
	int	nbr;
	int	c;

	nbr = 0;
	while (isdigit(c = getchar())) {
		nbr = 10 * nbr + c - '0';
	}
	return nbr;
}

Grid* get_grid()
{
	Grid*	g;
	int	i;
	int	j;

	g = malloc(sizeof(Grid));
	
	scanf("%d", &g->t);
	scanf("%d %d %d", &g->n, &g->m, &g->k);
	getchar();

	g->grid = malloc(g->n * sizeof(int*));
	for (i = 0; i < g->n; i++) {
		g->grid[i] = malloc(g->m * sizeof(int));
		for (j = 0; j < g->m; j++) {
			g->grid[i][j] = read_dig();
		}
	}

	return g;
}

void free_grid(Grid* g)
{
	int	i;

	for (i = 0; i < g->n; i++) {
		free(g->grid[i]);
	}
	free(g->grid);
	free(g);
}

int dist(int y1, int x1, int y2, int x2)
{
	return abs(y1 - y2) + abs(x1 - x2);
}
