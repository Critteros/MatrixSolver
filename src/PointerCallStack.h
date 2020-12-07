#pragma once
#include <stdbool.h>

typedef struct
{
	unsigned int size;
	int** pointers_array;
}DELETE_STRUCTURE;


typedef struct
{
	DELETE_STRUCTURE** structure_array;
	int size;
	int realSize;
	int top;
}POINTER_STACK;



void createEmptyStack(POINTER_STACK* stack);
void put(POINTER_STACK* stack, DELETE_STRUCTURE* structure);
DELETE_STRUCTURE* pop(POINTER_STACK* stack);
void resize(POINTER_STACK* stack);
DELETE_STRUCTURE* createDeleteStructure(int** t_array, unsigned int size);
void freeMemory(POINTER_STACK* ref);

