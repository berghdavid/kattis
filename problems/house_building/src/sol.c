#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sol.h"

void append_sq(Data* d, Sq* sq)
{
	Listq*	q;
	El*	el;
	El*	el2;

	q = d->best;

	if (q->size == d->g->k && sq->val <= q->last->sq->val) {
		return;
	}
	el = malloc(sizeof(El));
	el->sq = sq;
	el->next = NULL;
	el->prev = NULL;

	if (q->size == d->g->k) {
		el2 = q->last->prev;
		while (sq->val > el2->sq->val) {
			el2 = el2->prev;
		}
		el->next = el2->next;
		el->prev = el2;
		el2->next->prev = el;
		el2->next = el;

		el = q->last;
		q->last = q->last->prev;
		q->last->next = NULL;
		free(el);
	} else {
		if (q->first == NULL) {
			q->first = el;
			q->last = el;
		} else if (sq->val >= q->first->sq->val) {
			el->next = q->first;
			q->first->prev = el;
			q->first = el;
		} else if (sq->val <= q->last->sq->val) {
			el->prev = q->last;
			q->last->next = el;
			q->last = el;
		} else {
			el2 = q->last->prev;
			while (sq->val > el2->sq->val) {
				el2 = el2->prev;
			}
			el->prev = el2;
			el->next = el2->next;
			el2->next->prev = el;
			el2->next = el;
		}
		q->size++;
	}
}

void print_listq(Listq* q)
{
	El*	el;
	int	i;

	el = q->first;
	printf("\nSize: %d\n", q->size);
	printf(" --- 10 first ---\n");
	printf("Val | X \t| Y\n");
	printf("-----------------------\n");
	for (i = 0; i < 10; i++) {
		if (el == NULL) {
			break;
		}
		printf(" %.2d | %d \t| %d\n", el->sq->val, el->sq->x, el->sq->y);
		el = el->next;
	}

	el = q->last;
	printf("\n --- 10 last ---\n");
	printf("Val | X \t| Y\n");
	printf("-----------------------\n");
	for (i = 0; i < 10; i++) {
		if (el == NULL) {
			break;
		}
		printf(" %.2d | %d \t| %d\n", el->sq->val, el->sq->x, el->sq->y);
		el = el->prev;
	}

	i = 0;
	el = q->first;
	while (el != NULL) {
		el = el->next;
		i++;
	}
	printf("size::::: %d\n", i);
}

Data* init_data(Grid* g)
{
	Sq*		sq;
	Data*		d;
	long int	sum;
	int		i;
	int		j;

	d = malloc(sizeof(Data));
	d->best = malloc(sizeof(Listq));
	d->best->first = NULL;
	d->best->last = NULL;
	d->best->size = 0;

	d->g = g;
	d->grid = malloc(g->n * sizeof(Sq*));

	sum = 0;
	for (i = 0; i < g->n; i++) {
		d->grid[i] = malloc(g->m * sizeof(Sq));
		for (j = 0; j < g->m; j++) {
			sq = &d->grid[i][j];
			sq->x = j;
			sq->y = i;
			sq->val = g->grid[i][j];
			append_sq(d, sq);
			sum += g->grid[i][j];
		}
	}

	d->mv = (double) sum / (g->n * g->m);
	d->mn = sqrt(g->n * g->m / g->k);
	d->mh = d->mv * d->mn;

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
	El*	el;
	El*	eltmp;
	int	i;

	el = d->best->first;
	while (el != NULL) {
		eltmp = el->next;
		free(el);
		el = eltmp;
	}
	free(d->best);
	for (i = 0; i < d->g->n; i++) {
		free(d->grid[i]);
	}
	free(d->grid);
	free(d);
}

void brute_force(Grid* g)
{
	Data*	d;

	d = init_data(g);
	//print_data(d);
	print_listq(d->best);
	free_data(d);
}

void solve(Grid* g)
{
	//print_persons(g);
	brute_force(g);
}
