#include <stdlib.h>
#include <stdio.h>

#define ARRAYSIZE(a) (sizeof(a) / sizeof(a[0]))
#define NUM_ROWS(a) ARRAYSIZE(a)
#define NUM_COLS(a) ARRAYSIZE(a[0])

#define INITIAL_ROW 9
#define INITIAL_COL 9
#define MAGICAL_NUMBER 3
#define INITIAL_RESULT_ROW INITIAL_ROW / MAGICAL_NUMBER
#define INITIAL_RESULT_COL INITIAL_COL / MAGICAL_NUMBER

int matrix[INITIAL_ROW][INITIAL_COL] = {
{-8, 5, -2, 1, 2, 2, 0, 0, 0},
{-8, 5, -1, 0, 1, 0, 0, 0, 0},
{-8, 2, -3, 2, 2, 2, 0, 0, 0},
{-7, 5, -2, 0, 0, 0, 2, 2, 2},
{-6, 2, -1, 0, 0, 0, 0, 3, 0},
{-8, 5, -1, 0, 0, 0, 2, 2, 2},
{-1, 5, -2, 0, 0, 0, 2, 2, 2},
{-8, 0, -1, 0, 0, 0, 2, 2, 2},
{-4, 5, -3, 0, 0, 0, 2, 2, 2}
};

void printMatrix(int (*matrix)[INITIAL_COL], int rows, int cols) {
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			printf("%d ", matrix[x][y]);
		}
		printf("\n");
	}
}

void printDynamicMatrix(int *matrix, int rows, int cols) {
	int offset = 0;
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			offset = x * INITIAL_RESULT_COL + y;
			printf("%d ", matrix[offset]);
		}
		printf("\n");
	}
}

void resetDynamicMatrix(int *matrix, int rows, int cols) {
	int offset = 0;
	for (int x = 0; x < rows; x++) {
                for (int y = 0; y < cols; y++) {
			offset = x * INITIAL_RESULT_COL + y;
			matrix[offset] = 0;
		}
	}
}

void countHourglass(int (*matrix)[INITIAL_COL], int rows, int cols, int *matrixResult) {
	int i = 0, j = 0, offset = 0;
	int xi = 0, yj = 0;
        for (int x = 0; x < rows; x++) {
		i = x / MAGICAL_NUMBER;
                for (int y = 0; y < cols; y++) {
			j = y / MAGICAL_NUMBER;
			xi = x - (i * MAGICAL_NUMBER);
			yj = y - (j * MAGICAL_NUMBER);
//			printf(" xi = %d , yj = %d \n", x - (i * MAGICAL_NUMBER), y - (j * MAGICAL_NUMBER));
			if (xi == 1 && (yj == 0 || yj == 2 ))
				continue;

			offset = i * INITIAL_RESULT_COL + j;
			matrixResult[offset] += matrix[x][y];
		}
	}
}

int main() {
	//https://stackoverflow.com/questions/2128728/allocate-matrix-in-c
	int *matrixResult = (int *) malloc(INITIAL_RESULT_ROW * INITIAL_RESULT_COL * sizeof(int));

	int num_rows = NUM_ROWS(matrix);
	int num_cols = NUM_COLS(matrix);
	printMatrix(matrix, num_rows, num_cols);

	printf("\nResetting result matrix!\n");

	resetDynamicMatrix(matrixResult, INITIAL_RESULT_ROW, INITIAL_RESULT_COL);
	printDynamicMatrix(matrixResult, INITIAL_RESULT_ROW, INITIAL_RESULT_COL);

	printf("\nApplying new results!\n");

	countHourglass(matrix, num_rows, num_cols, matrixResult);
	printDynamicMatrix(matrixResult, INITIAL_RESULT_ROW, INITIAL_RESULT_COL);

	return 0;
}
