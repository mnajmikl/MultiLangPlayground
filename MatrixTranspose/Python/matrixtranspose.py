def creatematrix(rows, columns):
    """
    Returns a 2D list with size rows x columns
    The list is initialized with incremental values
    """
    return [[columns * j + i for i in range(columns)] for j in range(rows)]

def transposematrix(matrix, newrows, newcolumns):
    newmatrix = creatematrix(newrows, newcolumns)
    for j in range(newrows):
        for i in range(newcolumns):
            newmatrix[j][i] = matrix[i][j]
    return newmatrix
    
def printmatrix(matrix, rows, columns):
    for j in range(rows):
        for i in range(columns):
            print(f"{matrix[j][i]:>2} ", end='')
        print()
    print()

if __name__ == '__main__':
    rows = 6
    columns = 5
    mymatrix = creatematrix(rows, columns)
    print(f"New matrix has been created\n")
    printmatrix(mymatrix, rows, columns)
    mymatrix = transposematrix(mymatrix, columns, rows)
    print(f"After the matrix have been transposed\n")
    printmatrix(mymatrix, columns, rows)

    
