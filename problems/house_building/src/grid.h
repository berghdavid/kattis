#ifndef GRID_H
#define GRID_H

typedef struct Grid Grid;

struct Grid {
	int**	grid;	/* List of rows with grid ints	*/
	int	t;	/* Test case id			*/
	int	m;	/* Width of the grid (cols)	*/
	int	n;	/* Height of grid (rows)	*/
	int	k;	/* Number of people		*/
};

void print_grid(Grid* g);

int read_dig();

Grid* get_grid();

void free_grid(Grid* g);

int dist(int y1, int x1, int y2, int x2);

#endif
