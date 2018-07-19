#include <stdio.h>

#define ARRAYSIZE(a) (sizeof(a) / sizeof(a[0]))
#define NUM_ROWS(a) ARRAYSIZE(a)
#define NUM_COLS(a) ARRAYSIZE(a[0])

int matrix[6][6] = {
{1, 2, 2, 0, 0, 0},
{0, 1, 0, 0, 0, 0},
{2, 2, 2, 0, 0, 0},
{0, 0, 0, 2, 2, 2},
{0, 0, 0, 0, 3, 0},
{0, 0, 0, 2, 2, 2}
};

int main() {
	int num_rows = NUM_ROWS(matrix);
	int num_cols = NUM_COLS(matrix);

	for (int x = 0; x < num_rows; x++) {
		for (int y = 0; y < num_cols; y++) {
			printf("%d ", matrix[x][y]);
		}
		printf("\n");
	}

	printf("\nOi!\n");
	return 0;
}
