#include <stdio.h>
#include <stdlib.h>
#include "MatrixSolver.h"

int static AskUser(int X, int Y);


void MatrixEnter(int** matrix, unsigned int matrix_size, MATRIX_CURSOR* Cursor, int** mirrorMatrix)
{
	while ((unsigned int)Cursor->Y <= matrix_size)
	{


		//Row-column handler 
		while ((unsigned int)Cursor->X <= matrix_size)
		{
			PrintMatrix(matrix, matrix_size, Cursor, mirrorMatrix);
			matrix[(Cursor->Y) - 1][(Cursor->X) - 1] = AskUser(Cursor->X, Cursor->Y);
			mirrorMatrix[(Cursor->Y) - 1][(Cursor->X) - 1] = 1;


			Cursor->X = Cursor->X + 1;

		}

		Cursor->X = 1;
		Cursor->Y = Cursor->Y + 1;
	}


}

int static AskUser(int X, int Y)
{
	int value;
	printf("\nPlease enter element C[%d, %d]: ", Y, X);

	while (scanf("%d", &value) != 1)
	{
		printf("Please enter a valid number: ");
		//Clears STDIN
		scanf("%*[^\n]%*c");
	}



	return value;
}