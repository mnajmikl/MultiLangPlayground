#include <iostream>
#include <iomanip>

struct Matrix
{
    int rows;
    int columns;
    int** matrixdata;
    Matrix(int r, int c) : rows (r), columns(c)
    {
        this->matrixdata = new int*[r]();
        for (int i = 0; i < r; i++)
        {
            this->matrixdata[i] = new int[c]();
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < this->rows; i++)
        {
            delete[] this->matrixdata[i];
        }
        delete[] this->matrixdata;
    }
    void setdata()
    {
        for (int r = 0; r < this->rows; r++)
        {
            for (int c = 0; c < this->columns; c++)
            {
                this->matrixdata[r][c] = this->columns * r + c;
            }
        }
    }
};

Matrix* TransposeMatrix(Matrix* source)
{
    Matrix* m = new Matrix(source->columns, source->rows);
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
            std::cout << std::setw(2) << data[r][c] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    const int rows = 6;
    const int cols = 8;

    Matrix original {rows, cols};
    original.setdata();
    std::cout << "Original matrix [" << original.rows << ", " << original.columns <<"]\n";
    printmatrix(original.matrixdata, original.rows, original.columns);

    Matrix* m = TransposeMatrix(&original);
    std::cout << "\nTransposed matrix [" << m->rows << ", " << m->columns <<"]\n";
    printmatrix(m->matrixdata, m->rows, m->columns);

    m->setdata();
    std::cout << "\nAfter resetting data\nTransposed matrix [" << m->rows << ", " << m->columns <<"]\n";
    printmatrix(m->matrixdata, m->rows, m->columns);

    delete m;
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
