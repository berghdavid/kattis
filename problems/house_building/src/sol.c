#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sol.h"

void print_data(Data* d)
{
	printf("Mean val: %f\n", d->mv);
	printf("Mean dist: %f\n", d->mn);
	printf("Mean value: %f\n", d->mh);
}

void print_sol(Data* d)
{
	El*	el;
	int	i;
	int	sum;

	el = d->all->first;
	sum = 0;
	printf("Optimal set of squares\n");
	printf("------------------------\n");
	while (el != NULL) {
		sum += el->sq->score;
		printf("%d %d\n", el->sq->x, el->sq->y);
		el = el->next;
	}
	printf("Total score: %d\n", sum);
}

void print_listq(Listq* q)
{
	El*	el;
	int	i;

	el = q->first;
	printf("\nSize: %d\n", q->size);
	printf(" --- 10 first ---\n");
	printf("Pts  | X \t| Y\n");
	printf("-----------------------\n");
	for (i = 0; i < 10; i++) {
		if (el == NULL) {
			break;
		}
		printf(" %.4d | %d \t| %d\n", el->sq->score, el->sq->x, el->sq->y);
		el = el->next;
	}
}

Data* init_data(Grid* g)
{
	Sq*		sq;
	Data*		d;
	long int	sum;
	int		i;
	int		j;

	d = malloc(sizeof(Data));
	d->all = malloc(sizeof(Listq));
	d->all->first = NULL;
	d->all->last = NULL;
	d->all->size = 0;

	d->g = g;
	d->grid = malloc(g->n * sizeof(Sq**));

	sum = 0;
	for (i = 0; i < g->n; i++) {
		d->grid[i] = malloc(g->m * sizeof(Sq*));
		for (j = 0; j < g->m; j++) {
			d->grid[i][j] = NULL;
			sum += g->grid[i][j];
		}
	}

	d->mv = (double) sum / (g->n * g->m);
	d->mn = sqrt(g->n * g->m / g->k);
	d->mh = d->mv * d->mn;

	return d;
}

void free_data(Data* d)
{
	El*	el;
	El*	eltmp;
	int	i;

	el = d->all->first;
	while (el != NULL) {
		eltmp = el->next;
		free(el->sq);
		free(el);
		el = eltmp;
	}
	free(d->all);
	for (i = 0; i < d->g->n; i++) {
		free(d->grid[i]);
	}
	free(d->grid);
	free(d);
}

void append_sq(Listq* l, Sq* sq)
{
	El*	el;

	el = malloc(sizeof(El));
	el->sq = sq;
	el->next = NULL;

	if (l->last != NULL) {
		l->last->next = el;
	} else {
		l->first = el;
	}
	l->last = el;
}

void set_sq(Data* d, int x, int y)
{
	Sq*	sq;

	sq = malloc(sizeof(Sq));
	sq->adj = NULL;
	sq->score = 0;
	sq->x = x;
	sq->y = y;
	append_sq(d->all, sq);
	d->grid[x][y] = sq;
}

void set_squares(Data* d)
{
	int	i;
	int	dist;

	set_sq(d, 0, 0);
	set_sq(d, 0, d->g->n - 1);
	set_sq(d, d->g->m - 1, 0);
	set_sq(d, d->g->m - 1, d->g->n - 1);
	dist = d->g->m;
}

void brute_force(Grid* g)
{
	Data*	d;

	d = init_data(g);
	print_grid(g);
	set_squares(d);
	print_sol(d);
	free_data(d);
}

void solve(Grid* g)
{
	brute_force(g);
}
