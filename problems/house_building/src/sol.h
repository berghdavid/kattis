#ifndef SOL_H
#define SOL_H

typedef struct Data Data;
typedef struct Sq Sq;
typedef struct Listq Listq;

#include "grid.h"

struct Sq {
	Sq*	next;
	int	x;
	int	y;
	int	val;
};

struct Listq {
	Sq*	first;
	Sq*	last;
	int	size;
};

struct Data {
	Listq*	sqs;	/* A list of all squares	*/
	double	mn;	/* Mean distance to neighbour	*/
	double	mv;	/* Mean value in grid		*/
	double	mh;	/* Mean value from one house	*/
};

Listq* init_list(Grid* g, Data* d);

void print_listq(Listq* q);

void free_listq(Listq* q);

Data* init_data(Grid* g);

void print_data(Data* d);

void free_data(Data* d);

void solve(Grid* g);

#endif
