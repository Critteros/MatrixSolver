#include <stdio.h>
#include <stdlib.h>
#include "MatrixSolver.h"
#include "MatrixDeterminent.h"

int** sliceMatrix(int** original_matrix, unsigned int original_size, int collumn)
{
	unsigned int new_size = original_size - 1;
	int** new_array = createMatrixArray(new_size);
	collumn--;

	int new_array_row;
	int new_array_index;
	for (unsigned int row = 1; row < original_size; row++)
	{
		new_array_row = row - 1;
		new_array_index = 0;
		for (unsigned int element = 0; element < original_size; element++)
		{
			if (element != collumn)
			{
				new_array[new_array_row][new_array_index] = original_matrix[row][element];
				new_array_index++;
			}
		}
	}
	
	return new_array;
}