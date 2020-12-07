#include <stdio.h>
#include <stdlib.h>
#include "MatrixSolver.h"
#include "MatrixDebugPrint.h"
#pragma warning (disable: 4996 6031 6011 6386)
#define SEPARATOR printf("--------------------------------------------------------------------------\n")


const char ACCEPTABLE_VALUES[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '\0' };



int main(void)
{
	int matrixSizeInput;

	printf("Enter matrix size: ");
	//Handler for incorrect input
	
	do
	{
		while (scanf("%d", &matrixSizeInput) != 1)
		{
			printf("Please enter a valid matrix size: ");
			//Clears STDIN
			scanf("%*[^\n]%*c");
		}
		if (matrixSizeInput == 0)
		{
			printf("0 is not a valid matrix size\n");
			printf("Please enter a valid matrix size: ");
		}
		else if(matrixSizeInput <0)
		{
			printf("Negative numbers are not valid\n");
			printf("Please enter a valid matrix size: ");
		}
	} while (matrixSizeInput < 1);
	
	//Change to unsigned int
	unsigned int matrixSize = matrixSizeInput;

	SEPARATOR;
	printf("Podany rozmiar tabeli to [%u]\n", matrixSize);
	SEPARATOR;
	system("pause");
	system("cls");

	//INITIALIZATION OF MATRIX STRUCTURE
	int** matrix = createMatrixArray(matrixSize);
	int** mirrorMatrix = createMatrixArray(matrixSize);
	MATRIX_CURSOR cursor = { .X = -1, .Y = -1 };
	/////////////////////////////////////////
	
	//DebugPrintM(matrix, matrixSize);
	//DebugPrintM(mirrorMatrix, matrixSize);
	
	PrintMatrix(matrix, matrixSize, &cursor, mirrorMatrix);
	



	deleteMatrixArray(matrix, matrixSize);
	deleteMatrixArray(mirrorMatrix, matrixSize);
	return 0;
}

int** createMatrixArray(unsigned int a_size)
{
	//Creates an array of int pointers with size of the given argument
	int** return_array = (int**)malloc(a_size * sizeof(int*));

	//Init array
	for (unsigned int i = 0; i < a_size; i++)
	{
		return_array[i] = NULL;
	}

	int* tmppointer = NULL;
	for (unsigned int i = 0; i < a_size; i++)
	{
		tmppointer = (int*)malloc(a_size * sizeof(int));
		
		//Init values
		for (unsigned int z = 0; z < a_size; z++)
		{
			tmppointer[z] = 0;
		}
		
		return_array[i] = tmppointer;
		tmppointer = NULL;
	}
	return return_array;

}

//Handle memory clearing
void deleteMatrixArray(int** t_array, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		free(t_array[i]);
	}
	free(t_array);
}

void PrintMatrix(int** matrix, unsigned int matrix_size, MATRIX_CURSOR *currCursor, int** mirrorMatrix)
{
	printf("The X value is %d and the Y value is %d", currCursor->X, currCursor->Y);
}