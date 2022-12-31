#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



void print2d(int** a, int s1, int s2)
{
	int i, j;
	for (i = 0; i < s1; i++)
	{
		printf("{");
		for (j = 0; j < s2; j++)
		{
			printf("%2d%c", a[i][j], (j == s2 - 1) ? '\0' : ',');
		}
		printf("}\n");
	}
}
void init_arr(int** a, int s1, int s2)
{
	int i, j;
	for (i = 0; i < s1; i++)
	{
		for (j = 0; j < s2; j++)
			a[i][j] = (i + 1) * (j + 1);
	}
}
int** alloc_arr(int s1, int s2)
{
	int i;
	int** a = NULL;

	a = (int**)malloc(sizeof(int*) * s1);
	assert(a != NULL && "d1 malloc");
	for (i = 0; i < s1; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * s2);
		assert(a[i] != NULL && "d2 malloc");
	}

	return a;
}
void free_arr(int** a, int s1)
{
	int i;
	for (i = 0; i < s1; i++)
	{
		free(a[i]);
	}
	free(a);
}
int** cp_arr_2d(int** a, int s1, int s2)
{
	int i, j;
	int** b = NULL;

	b = alloc_arr(s1, s2);
	for (i = 0; i < s1; i++)
	{
		for (j = 0; j < s2; j++)
			*(*(b + i) + j) = a[i][j];
	}
	return b;
}
