#pragma once

#pragma warning (disable: 4996 6031 6011 6386)
#define SEPARATOR printf("--------------------------------------------------------------------------\n")


typedef struct
{
	int X;
	int Y;
} MATRIX_CURSOR;

//MAIN file functions
int** createMatrixArray(unsigned int a_size);
void deleteMatrixArray(int** t_array, unsigned int size);
void PrintMatrix(int** matrix, unsigned int matrix_size, MATRIX_CURSOR *Cursor, int** mirrorMatrix);
void DebugPrintM(int** t_array, unsigned int t_size);

//MatrixEnter.c
void MatrixEnter(int** matrix, unsigned int matrix_size, MATRIX_CURSOR* Cursor, int** mirrorMatrix);
