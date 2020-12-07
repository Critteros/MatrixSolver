#pragma once
#include <stdio.h>
void DebugPrintM(int** t_array, unsigned int t_size);


void DebugPrintM(int** t_array, unsigned int t_size)
{
	printf("-----------DEBUG_PRINT-----------\n\n");
	//Iterate over rows
	int* currRow = NULL;
	for (unsigned int row = 0; row < t_size ; row++)
	{
		currRow = t_array[row];
		printf("| [");
		//Iterate over elements
		for (unsigned int element = 0; element < (t_size - 1); element++)
		{
			printf("%d, ", currRow[element]);
		}
		printf("%d", currRow[t_size - 1]);
		printf("] |\n");
		currRow = NULL;
	}
	printf("\n-----------DEBUG_PRINT-----------\n\n");

}