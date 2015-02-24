#include <Windows.h>
#include <iostream>
#include <algorithm>

using namespace std;

// GLOBAL VARIABLE
const int rows = 3 + 2, colls = 4 + 2;
int matrix_info[rows][colls] = { 0 };
double matrix_values[rows][colls] = { 0 };
double R[3] = { 0.1, 0.8, 0.1 };
double step = -3;
int cell[2] = { -1 };

// FUNCTIONS
bool matrix_find_computed_cell(int(&cell)[2]);
void calculate_cell(int cell[2]);
void restore_matrix_info();
void print_matrix(double matrix[rows][colls]);