#include <stdio.h>
#include <stdlib.h>
#include "PointerCallStack.h"


void createEmptyStack(POINTER_STACK* stack)
{
	stack->realSize = 1;
	stack->pointers_array = (int**)malloc(sizeof(int**));
	stack->top = -1;
	stack->size = 0;
}

void put(POINTER_STACK* stack, int** arrPointer)
{
	stack->pointers_array[stack->size] = arrPointer;
	stack->top = stack->top + 1;
	stack->size = stack->size + 1;
}

int** pop(POINTER_STACK* stack)
{
	int oldTop = stack->top;
	stack->top = stack->top - 1;
	stack->size = stack->size - 1;
	return (stack->pointers_array[oldTop]);

}

