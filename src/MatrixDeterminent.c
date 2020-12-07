#include <stdio.h>
#include <stdlib.h>
#include "MatrixSolver.h"
#include "MatrixDeterminent.h"

static int calculateSign(int el);

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

static int calculateSign(int el)
{
	if ((el + 2) % 2 == 0)
		return 1;
	else
		return -1;
}

int calculateDeterminent(int** matrix, unsigned int size)
{
	int r_value = 0;
	if (size == 1)
		return matrix[0][0];
	else
	{
		for (unsigned int i = 0; i < size; i++)
		{
			int** sliced = sliceMatrix(matrix, size, i+1);
			//DebugPrintM(sliced, size - 1);
			r_value += calculateSign(i) * matrix[0][i] * calculateDeterminent(
				sliced,
				size - 1
			);
		}
	}
	return r_value;
}