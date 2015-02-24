#include "main_header.h"

// FIND CELL WITH IDENTIFIERS 1
// return false on fail/ true on success
// return int[2] with coordinates by reference
bool matrix_find_computed_cell(int (&cell)[2]) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colls; j++)
			if (matrix_info[i][j] == + 1) {
				cell[0] = i;
				cell[1] = j;
				return true;
			}
	return false;
}

// CALCULATE CELL .. by all four ways from it, choose and save best option (best profit)
// return nothing
void calculate_cell(int (&cell)[2]) {
	double values[4] = { 0 };

	// COMPUTE PROFIT FOR EVERY WAY INSIDE THIS CELL
	values[0] = way_probability[0] * matrix_values[cell[0]][cell[1] - 1] + way_probability[1] * matrix_values[cell[0] - 1][cell[1]] + way_probability[2] * matrix_values[cell[0]][cell[1] + 1] + R;  // up
	values[1] = way_probability[0] * matrix_values[cell[0] - 1][cell[1]] + way_probability[1] * matrix_values[cell[0]][cell[1] + 1] + way_probability[2] * matrix_values[cell[0] + 1][cell[1]] + R;  // right
	values[2] = way_probability[0] * matrix_values[cell[0]][cell[1] + 1] + way_probability[1] * matrix_values[cell[0] + 1][cell[1]] + way_probability[2] * matrix_values[cell[0]][cell[1] - 1] + R;  // down
	values[3] = way_probability[0] * matrix_values[cell[0] + 1][cell[1]] + way_probability[1] * matrix_values[cell[0]][cell[1] - 1] + way_probability[2] * matrix_values[cell[0] - 1][cell[1]] + R;  // left

	// highest profit
	matrix_values[cell[0]][cell[1]] = *max_element(values, values + 4);

	matrix_info[cell[0]][cell[1]] = 1;
}

// RESTORE matrix_info TO DEFAULT
void restore_matrix_info() {
	for (int i = 1; i < rows - 1; i++)
		for (int j = 1; j < colls; j++)
			matrix_info[i][j] = 0; // ordinary cell

	// OBSOLETE CELLS
	// edges:
	for (int j = 0; j < colls; j++) matrix_info[0][j] = -1;  // edges i = 0
	for (int j = 0; j < colls; j++) matrix_info[rows - 1][j] = -1;  // edges i = rows - 1
	for (int i = 0; i < rows; i++) matrix_info[i][0] = -1;  // edges j = 0
	for (int i = 0; i < rows; i++) matrix_info[i][colls - 1] = -1;  // edges j = colls - 1

	// special cells:
	matrix_info[2][2] = -1; // obstacle
	matrix_info[1][4] = +1; // + 100 .. absroption cell, their neighbours will be computed at first
	matrix_info[2][4] = -1; // - 100 .. absorption cell 
}

// PRINT MATRIX
void print_matrix(double (&matrix)[rows][colls]) {
	cout.precision(4);
	for (int i = 1; i < rows - 1; i++) {
		for (int j = 1; j < colls - 1; j++)
			cout << fixed << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}