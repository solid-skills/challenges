#include <stdlib.h>
#include <stdio.h>

#define ARRAYSIZE(a) (sizeof(a) / sizeof(a[0]))
#define NUM_ROWS(a) ARRAYSIZE(a)
#define NUM_COLS(a) ARRAYSIZE(a[0])

#define INITIAL_ROW 6
#define INITIAL_COL 6
#define MAGICAL_NUMBER 3

int matrix[INITIAL_ROW][INITIAL_COL] = {
{1, 2, 2, 0, 0, 0},
{0, 1, 0, 0, 0, 0},
{2, 2, 2, 0, 0, 0},
{0, 0, 0, 2, 2, 2},
{0, 0, 0, 0, 3, 0},
{0, 0, 0, 2, 2, 2}
};

void printMatrix(int (*matrix)[INITIAL_COL], int rows, int cols) {
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			printf("%d ", matrix[x][y]);
		}
		printf("\n");
	}
}

int main() {
	//https://stackoverflow.com/questions/2128728/allocate-matrix-in-c
	int *matrixResult = (int *) malloc(INITIAL_ROW/MAGICAL_NUMBER * INITIAL_COL/MAGICAL_NUMBER * sizeof(int));
	//int *matrixResult = (int) malloc(2 * 2 * sizeof(int));

	int num_rows = NUM_ROWS(matrix);
	int num_cols = NUM_COLS(matrix);
	printMatrix(matrix, num_rows, num_cols);

	printf("\nOi!\n");

//	printMatrix(matrixResult);

	return 0;
}
