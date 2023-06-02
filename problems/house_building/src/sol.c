#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sol.h"

void append_sq(Data* d, Listq* q, Sq* sq)
{
	if (sq->val > d->mv) {
		sq->next = q->first;
		q->first = sq->next;
	} else {
		if (q->last != NULL) {
			q->last->next = sq;
		}
		q->last = sq;
	}
}

Listq* init_list(Grid* g, Data* d)
{
	Listq*	q;
	Sq*	sq;
	int	i;
	int	j;

	q = malloc(sizeof(Listq));
	q->first = NULL;
	q->last = NULL;

	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->m; j++) {
			sq = malloc(sizeof(Sq));
			sq->next = NULL;
			sq->x = j;
			sq->y = i;
			sq->val = g->g[i][j];
			append_sq(d, q, sq);
		}
	}
	return q;
}

void print_listq(Listq* q)
{
	/* TODO::::: */
}

void free_listq(Listq* q)
{
	Sq*	sq;
	Sq*	tmp;

	sq = q->first;
	while (sq != NULL) {
		tmp = sq->next;
		free(sq);
		sq = tmp;
	}
	free(q);
}

Data* init_data(Grid* g)
{
	Data*		d;
	long int	sum;
	int		i;
	int		j;

	sum = 0;
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->m; j++) {
			sum += g->g[i][j];
		}
	}


	d = malloc(sizeof(Data));
	d->mv = (double) sum / (g->n * g->m);
	d->mn = sqrt(g->n * g->m / g->k);
	d->mh = d->mv * d->mn;
	d->sqs = init_list(g, d);

	return d;
}

void print_data(Data* d)
{
	printf("Mean val: %f\n", d->mv);
	printf("Mean dist: %f\n", d->mn);
	printf("Mean value: %f\n", d->mh);
}

void free_data(Data* d)
{
	free_listq(d->sqs);
	free(d);
}

void brute_force(Grid* g)
{
	Data*	d;

	d = init_data(g);
	print_data(d);
	print_listq(d->sqs);
	free_data(d);
}

void solve(Grid* g)
{
	print_persons(g);
	brute_force(g);
}
