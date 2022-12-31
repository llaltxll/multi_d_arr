#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define SIZE1 10
#define SIZE2 10

void print2d(int** a);
void init_arr(int** a);

int main() {
	int i;
	int** arr = NULL;
	arr = (int**)malloc(sizeof(int*) * SIZE1);
	assert(arr != NULL && "d1 malloc");
	for (i = 0; i < SIZE2; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * SIZE2);
		assert(arr[i] != NULL && "d2 malloc");
	}
	init_arr(arr);
	print2d(arr);

	
	return 0;
}

void print2d(int** a) 
{
	int i, j;
	for (i = 0; i < SIZE1; i++)
	{
		printf("{");
		for (j = 0; j < SIZE2; j++)
		{	
			printf("%3d%c", a[i][j], (j == SIZE2 - 1)?'\0' : ',');
		}
		printf("}\n\n");
	}
}
void init_arr(int** a)
{
	int i, j;
	for (i = 0; i < SIZE1; i++)
	{
		for (j = 0; j < SIZE2; j++)
			a[i][j] = (i+1) * (j+1);
	}
}