#include <stdio.h>
#include "MatrixSolver.h"
#pragma warning (disable: 4996 6031)

const char ACCEPTABLE_VALUES[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '\0' };

int main(void)
{
	int matrixSize;

	
	printf("Podaj rozmiar macierzy kwadratowej: ");
	//Handler for incorrect input
	while (scanf("%d", &matrixSize) != 1)
	{
		printf("Podaj prawid³owy rozmiar macierzy: ");
		//Clears STDIN
		scanf("%*[^\n]%*c");
	}
	

	
	return 0;
}