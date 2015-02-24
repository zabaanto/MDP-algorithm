#include "main_header.h"

// GLOBAL VARIABLES DEFINITIONS
double	matrix_info[rows][colls] = { 0 };
double	matrix_values[rows][colls] = { 0 };
double	way_probability[3] = { 0.1, 0.8, 0.1 };
double	R = -3;
int			cell[2] = { -1 };

void main()
{
	restore_matrix_info();

	// INITIAL VALUES
	matrix_values[1][4] = + 100;
	matrix_values[2][4] = - 100;

	// infinite loop
	while (true)
	{
		// while still finding some cell with identifer 1
		while (matrix_find_computed_cell(cell) == true)
		{
			matrix_info[cell[0]][cell[1]] = -1; // no longer used

			// FIND ADJECENT CELLS IN FOUR DIRECTIONS
			if (matrix_info[cell[0] - 1][cell[1]] == 0) { int cell_to_calculate[2] = { cell[0] - 1, cell[1] }; calculate_cell(cell_to_calculate); }  // up
			if (matrix_info[cell[0] + 1][cell[1]] == 0) { int cell_to_calculate[2] = { cell[0] + 1, cell[1] }; calculate_cell(cell_to_calculate); }  // down
			if (matrix_info[cell[0]][cell[1] - 1] == 0) { int cell_to_calculate[2] = { cell[0], cell[1] - 1 }; calculate_cell(cell_to_calculate); }  // left
			if (matrix_info[cell[0]][cell[1] + 1] == 0) { int cell_to_calculate[2] = { cell[0], cell[1] + 1 }; calculate_cell(cell_to_calculate); }  // right
		}

		restore_matrix_info();
		print_matrix(matrix_values);
		Sleep(500);
	}	

}