#pragma once

//MAIN file functions
typedef struct
{
	int X;
	int Y;
} MATRIX_CURSOR;


int** createMatrixArray(unsigned int a_size);
void deleteMatrixArray(int** t_array, unsigned int size);
void PrintMatrix(int** matrix, unsigned int matrix_size, MATRIX_CURSOR* currCursor, int** mirrorMatrix);
