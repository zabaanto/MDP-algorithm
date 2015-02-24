
#include <Windows.h>
#include <iostream>
#include <algorithm>

using namespace std;

// GLOBAL CONSTANT - DEFINITIONS
const int rows = 3 + 2;
const int colls = 4 + 2;

// GLOBAL VARIABLES - EXTERN DECLARATIONS
extern double	matrix_info[][colls];
extern double matrix_values[][colls];
extern double way_probability[];
extern double	R;
extern int		cell[];

// FUNCITONS
bool matrix_find_computed_cell(int (&cell)[2]);
void calculate_cell(int (&cell)[2]);
void restore_matrix_info();
void print_matrix(double (&matrix)[rows][colls]);

/* ***** INFO **** */
/* CELL IDENTIFIERS IN matrix_info:
		- 1 .. obsolete cell .. edges, obstacles, absorption cells .. will not be computed
		  0 .. ordinary cell .. coudl get through it, possible way
		+ 1 .. cell just computed .. adjecent cells will be computed next time
 */