#ifndef SOL_H
#define SOL_H

typedef struct Sq Sq;
typedef struct El El;
typedef struct Listq Listq;
typedef struct Data Data;

#include "grid.h"

struct Sq {
	int	x;
	int	y;
	int	score;
	El*	adj;
};

struct El {
	Sq*	sq;
	El*	next;
};

struct Listq {
	El*	first;
	El*	last;
	int	size;
};

struct Data {
	Sq***	grid;	/* A grid containing structs	*/
	Grid*	g;	/* Points to original grid obj	*/
	Listq*	all;	/* A list of the k best squares	*/
	double	mn;	/* Mean distance to neighbour	*/
	double	mv;	/* Mean value in grid		*/
	double	mh;	/* Mean value from one house	*/
};

void print_sol(Data* d);

Listq* init_list(Grid* g, Data* d);

void print_listq(Listq* q);

void free_listq(Listq* q);

Data* init_data(Grid* g);

void print_data(Data* d);

void free_data(Data* d);

void solve(Grid* g);

#endif
