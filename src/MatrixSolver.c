#include <stdio.h>
#include <stdlib.h>
#include "MatrixSolver.h"
#include "PointerCallStack.h"
#include "MatrixDeterminent.h"


POINTER_STACK queque;

const char ACCEPTABLE_VALUES[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '\0' };



int main(void)
{
	createEmptyStack(&queque);
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
	MATRIX_CURSOR cursor = { .Y = 1, .X = 1};
	/////////////////////////////////////////
	

	//DebugPrintM(matrix, matrixSize);
	//DebugPrintM(mirrorMatrix, matrixSize);

	MatrixEnter(matrix, matrixSize, &cursor, mirrorMatrix);
	PrintMatrix(matrix, matrixSize, &cursor, mirrorMatrix);
	
	int result = calculateDeterminent(matrix, matrixSize);
	printf("\nDeterminant is equal [%d]\n", result);

	
	freeMemory(&queque);
	
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
	DELETE_STRUCTURE* deleter = createDeleteStructure(return_array, a_size);
	put(&queque, deleter);
	
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

void PrintMatrix(int** matrix, unsigned int matrix_size, MATRIX_CURSOR *Cursor, int** mirrorMatrix)
{
	system("cls"); //Cleaning the screen
	//Main loop that will handle each row of matrix

	char rectangle = 219;

	int currX = 1;
	int currY = 1;

	//Skip one line
	printf("\n");
	
	//Handling indywidual elements of an array
	int realElement;
	int mirrorElement;
	/////////////////////////
	
	for (unsigned int row = 0; row < matrix_size; row++)
	{
		printf(" | ");
		
		//Main loop that will handle each row-column
		for (unsigned int element = 0; element < matrix_size; element++)
		{
			realElement = matrix[row][element];
			mirrorElement = mirrorMatrix[row][element];
			//For each element in each row-collumn check with mirrorMatrix
			//If mirror matrix value is 1 for a given element then
			//It is taken as an user-written value
			//else if mirrorMatrix value is 0 for a given element
			//it is taken as an to write value
			if (mirrorElement == 1)
			{
				if ((currX == Cursor->X) && (currY == Cursor->Y))
				{
					printf("%c ", rectangle);
				}
				else
				{
					printf("%d ", realElement);
				}
				
			}
			else if (mirrorElement == 0)
			{
				if ((currX == Cursor->X) && (currY == Cursor->Y))
				{
					printf("%c ", rectangle);
				}
				else
				{
					printf("# ");
				}
				
				
			}
			else
			{
				printf("ERROR: mirror element was not 0 or 1 mirrorElement=[%d]", mirrorElement);
				exit(1);
			}
			currX++;
		} //END OF EACH ELEMENT LOOP
		printf("|\n");

		currY++;
		currX = 1;
	}
}

void DebugPrintM(int** t_array, unsigned int t_size)
{
	printf("-----------DEBUG_PRINT-----------\n\n");
	//Iterate over rows
	int* currRow = NULL;
	for (unsigned int row = 0; row < t_size; row++)
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

