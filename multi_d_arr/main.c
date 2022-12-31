#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define SIZE1 9
#define SIZE2 9

void print2d(int** a, int s1, int s2);
void init_arr(int** a, int s1, int s2);
int** alloc_arr(int s1, int s2);
void free_arr(int** a, int s1);
int** cp_arr_2d(int** a, int s1, int s2);

int main() {
	/* 2LEARN: if insterad we initialize arr here to NULL
	 * pass pointer to alloc_arr() and malloc there
	 * we get an access violation
	 */
	int** arr = alloc_arr(SIZE1, SIZE2);
	int** arr2 = NULL;
	/* int arr3[][9] is the same as *arr[9]
	 * which makes it incompatible with int **
	 */
	init_arr(arr, SIZE1, SIZE2);
	print2d(arr, SIZE1, SIZE2);

	arr2 = cp_arr_2d(arr, SIZE1, SIZE2);
	print2d(arr2, SIZE1, SIZE2);

	free_arr(arr, SIZE1);
	free_arr(arr2, SIZE1);
	return 0;
}
