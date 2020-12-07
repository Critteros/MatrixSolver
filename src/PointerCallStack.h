#pragma once

typedef struct
{
	int** pointers_array;
	int size;
	int realSize;
	int top;
}POINTER_STACK;



void createEmptyStack(POINTER_STACK* stack);
void put(POINTER_STACK* stack, int** arrPointer);
int** pop(POINTER_STACK* stack);

