#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
	int rows;
	int columns;
	int** matrixdata;
};

int** initdata(int rows, int columns)
{
	int** data = (int**) malloc(sizeof(int*) * rows);
	for (int i = 0; i < rows; i++)
	{
		data[i] = (int*) malloc(sizeof(int) * columns);
	}
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			data[r][c] = 0;
		}
	}
	return data;
}

void setdata(int** d, int rows, int columns)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			d[r][c] = columns * r + c;
		}
	}
}

struct Matrix* TransposeMatrix( struct Matrix* source, int newrows, int newcols)
{
	struct Matrix* m = (struct Matrix *) malloc(sizeof(struct Matrix));
	m->rows = newrows;
	m->columns = newcols;
	m->matrixdata = initdata(newrows, newcols);
	for (int r = 0; r < source->columns; r++)
	{
		for (int c = 0; c < source->rows; c++)
		{
			m->matrixdata[r][c] = source->matrixdata[c][r];
		}
	}
	return m;
}

void printmatrix(int** data, int rows, int columns)
{
	for (int r = 0; r < rows ; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			printf("%2d ", data[r][c]);
		}
		printf("\n");
	}
}

int main()
{
	const int rows = 5;
	const int cols = 7;
	
	struct Matrix original;
	original.rows = rows;
	original.columns = cols;
	original.matrixdata = initdata(rows, cols);
	setdata(original.matrixdata, rows, cols);
	printf("Original matrix [%d,%2d]\n", original.rows, original.columns);
	printmatrix(original.matrixdata, original.rows, original.columns);
	
	struct Matrix* m = TransposeMatrix(&original, cols, rows);
	printf("\nTransposed matrix [%d,%2d]\n", m->rows, m->columns);
	printmatrix(m->matrixdata, m->rows, m->columns);
	
	setdata(m->matrixdata, m->rows, m->columns);
	printf("\nAfter resetting data\nTransposed matrix [%d,%2d]\n", m->rows, m->columns);
	printmatrix(m->matrixdata, m->rows, m->columns);
	
	free(m);
	return 0;
}

///
// Formula to tabulate matrix with default sequential values
// r = current row
// c = current column
// columns = number of columns
//
// Cell value = columns * r + c
//
// e.g. rows = 2, columns = 3
// 0,0 = 3 * 0 + 0 = 0
// 0,1 = 3 * 0 + 1 = 1
// 0,2 = 3 * 0 + 2 = 2
// 1,0 = 3 * 1 + 0 = 3
// 1,1 = 3 * 1 + 1 = 4
// 1,2 = 3 * 1 + 2 = 5
///

///
// Matrix transposition
// dest->matrixdata[r][c] = source->matrixdata[c][r]
//
// e.g.
// Original rows = 2, columns = 3
// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 
// Transposed rows = 3, columns = 2
// 0,0 0,1
// 1,0 1,1
// 2,0 2,1
///
