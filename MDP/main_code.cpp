#include "main_header.h"

// GLOBAL VARIABLES DEFINITIONS
double	matrix_info[rows][colls] = { 0 };
double	matrix_values[rows][colls] = { 0 };
char    matrix_directions[rows][colls];
double	way_probability[3] = { 0.2, 0.8, 0.2 };
double	R = -3;
int			cell[2] = { -2 };
int			loops = 15;

void main()
{
	initial_values();

	int count_loop = 0;
	while (loops >= count_loop)
	{
		// while still finding some cell with identifer 1
		while (matrix_find_computed_cell(cell) == true)
		{
			matrix_info[cell[0]][cell[1]] = -1; // no longer used

			// FIND ADJECENT CELLS IN FOUR DIRECTIONS
			int pointers[4][2] = { { -1, 0 }, { +1, 0 }, { 0, -1 }, { 0, +1 } }; // UP, RIGHT, DOWN, LEFT
			for (int i = 0; i < 4; i++)
			{
				int coordinates[2] = { cell[0] + pointers[i][0], cell[1] + pointers[i][1] };  // prepare coordinates into array
				if (matrix_info[coordinates[0]][coordinates[1]] == 0) calculate_cell(coordinates);  // cell with identifier 0 => calculate
			}
		}

		system("cls");
		//
		cout.precision(4);
		print_matrix(matrix_values);
		//
		cout.precision(0);
		print_matrix(matrix_directions);
		//
		restore_matrix_info();
		Sleep(500);
		count_loop++;
	}	

}