#include <stdio.h>
#include <stdlib.h>
#include "MatrixSolver.h"
#include "PointerCallStack.h"
#pragma warning (disable: 6011 6386)


void createEmptyStack(POINTER_STACK* stack)
{
	stack->realSize = 1;
	stack->structure_array = (DELETE_STRUCTURE**)malloc(sizeof(DELETE_STRUCTURE*));
	stack->top = -1;
	stack->size = 0;
}

void put(POINTER_STACK* stack, DELETE_STRUCTURE* structure)
{
	if (stack->size == stack->realSize)
		resize(stack);
	
	stack->structure_array[stack->size] = structure;
	stack->top = stack->top + 1;
	stack->size = stack->size + 1;
}

DELETE_STRUCTURE* pop(POINTER_STACK* stack)
{
	int oldTop = stack->top;
	stack->top = stack->top - 1;
	stack->size = stack->size - 1;
	return (stack->structure_array[oldTop]);
}

bool isEmpty(POINTER_STACK* stack)
{
	if ((stack->top) == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void resize(POINTER_STACK* stack)
{
	int old_size_real = stack->realSize;
	DELETE_STRUCTURE** old_array = stack->structure_array;

	
	DELETE_STRUCTURE** new_array = (DELETE_STRUCTURE**)malloc(2 * old_size_real*sizeof(DELETE_STRUCTURE*));

	//Copying array
	for (int i = 0; i <= stack->top; i++)
	{
		new_array[i] = old_array[i];
	}
	stack->realSize = 2 * old_size_real;
	stack->structure_array = new_array;
	free(old_array);
}

DELETE_STRUCTURE* createDeleteStructure(int** t_array, unsigned int size)
{
	DELETE_STRUCTURE* tmp = (DELETE_STRUCTURE*)malloc(sizeof(DELETE_STRUCTURE));
	tmp->pointers_array = t_array;
	tmp->size = size;
	return tmp;
}


void freeMemory(POINTER_STACK* ref)
{
	while (!isEmpty(ref))
	{
		DELETE_STRUCTURE* currElement = pop(ref);
		//printf("Popped \n");
		deleteMatrixArray(currElement->pointers_array, currElement->size);
		free(currElement);
	}
	
}