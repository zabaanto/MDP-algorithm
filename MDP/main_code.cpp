#include "main_header.h"

void main()
{
	restore_matrix_info();

	// initial values
	matrix_values[1][4] = + 100;
	matrix_values[2][4] = - 100;

	// INFINITE LOOPS
	while (true)
	{
		while (matrix_find_computed_cell(cell) == true)
		{
			matrix_info[cell[0]][cell[1]] = -1;

			// find adjecenet cells in four directions
			if (matrix_info[cell[0] - 1][cell[1]] == 0) { int cell_to_calculate[2] = {cell[0] -1, cell[1]}; calculate_cell(cell_to_calculate); }  // up
			if (matrix_info[cell[0] + 1][cell[1]] == 0) { int cell_to_calculate[2] = { cell[0] + 1, cell[1] }; calculate_cell(cell_to_calculate); }  // down
			if (matrix_info[cell[0]][cell[1] - 1] == 0) { int cell_to_calculate[2] = { cell[0], cell[1] - 1 }; calculate_cell(cell_to_calculate); }  // left
			if (matrix_info[cell[0]][cell[1] + 1] == 0) { int cell_to_calculate[2] = { cell[0], cell[1] + 1 }; calculate_cell(cell_to_calculate); }  // right

			Sleep(200);
		}

		print_matrix(matrix_values);
		cout << endl;
		restore_matrix_info();
		Sleep(200);
	}	
}

bool matrix_find_computed_cell(int (&cell)[2]) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colls; j++)
			if (matrix_info[i][j] == +1) {
				cell[0] = i;
				cell[1] = j;
				return true;
			}
	return false;
}

void calculate_cell(int cell[2]) {
	double values[4] = { 0 };

	//cout << cell[0] << ":" << cell[1] << endl;

	// COMPUTE PROFIT FOR EVERY WAY INSIDE THIS CELL
	values[0] = R[0] * matrix_values[cell[0]][cell[1] - 1] + R[1] * matrix_values[cell[0] - 1][cell[1]] + R[2] * matrix_values[cell[0]][cell[1] + 1] + step;  // up
	values[1] = R[0] * matrix_values[cell[0] - 1][cell[1]] + R[1] * matrix_values[cell[0]][cell[1] + 1] + R[2] * matrix_values[cell[0] + 1][cell[1]] + step;  // right
	values[2] = R[0] * matrix_values[cell[0]][cell[1] + 1] + R[1] * matrix_values[cell[0] + 1][cell[1]] + R[2] * matrix_values[cell[0]][cell[1] - 1] + step;  // down
	values[3] = R[0] * matrix_values[cell[0] + 1][cell[1]] + R[1] * matrix_values[cell[0]][cell[1] - 1] + R[2] * matrix_values[cell[0] - 1][cell[1]] + step;  // left

	// HIGHEST PROFIT
	matrix_values[cell[0]][cell[1]] = *max_element(values, values + 4);

	matrix_info[cell[0]][cell[1]] = 1;
}

void restore_matrix_info() {
	for (int i = 1; i < rows - 1; i++)
		for (int j = 1; j < colls; j++)
			matrix_info[i][j] = 0;

	// edges:
	for (int j = 0; j < colls; j++) matrix_info[0][j] = -1;  // edges i = 0
	for (int j = 0; j < colls; j++) matrix_info[rows - 1][j] = -1;  // edges i = rows - 1
	for (int i = 0; i < rows; i++) matrix_info[i][0] = -1;  // edges j = 0
	for (int i = 0; i < rows; i++) matrix_info[i][colls - 1] = -1;  // edges j = colls - 1

	// special cells:
	matrix_info[2][2] = -1;
	matrix_info[1][4] = +1;
	matrix_info[2][4] = -1;
}

void print_matrix(double matrix[rows][colls]) {
	for (int i = 1; i < rows - 1; i++) {
		for (int j = 1; j < colls - 1; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}