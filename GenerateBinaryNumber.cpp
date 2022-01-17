// GenerateBinaryNumber.cpp

#include <cstdlib>
#include <iostream>

using namespace std;

void generatebinarynumber(int);
void generatebinarynumber2(int);

int main()
{
    generatebinarynumber(132);
    generatebinarynumber2(132);
    return 0;
}

void generatebinarynumber(int decimal)
{
    int length = 0;
    int copy = decimal;

    /*
     * Find the length of the array to store the "binary" 
     * numbers (remainders from division by 2)
     */
    while (copy > 0)
    {
        copy = copy / 2;
        length += 1;
    }

    // Dynamic integer array that stores the "binary" numbers
    int *binnumber;
    binnumber = (int *) calloc(length, sizeof(int));

    if (binnumber == NULL)
    {
        cout << "Cannot allocate memory";
        exit(0);
    }
    
    int length_copy = 0;

    /*
     * 1. Store the remainder of decimal division by 2 
     * 2. Divide the decimal using integer division by 2
     *    The result is the reversed version of the binary number
     */
    while (decimal > 0)
    { 
        *(binnumber + length_copy) = decimal % 2;
        decimal = decimal / 2;
        length_copy++;
    }

    /*
     * Print the array from above in reverse 
     */
    for (int i = length - 1; i >= 0; i--)
    {
        cout <<  " " << * (binnumber + i) << " ";
    }

    cout << endl;

    free(binnumber);
}

void generatebinarynumber2(int decimal)
{
    int length = 0;
    int copy = decimal;

    /*
     * Find the length of the array to store the "binary"
     * numbers (remainders from division by 2)
     */
    while (copy > 0)
    {
        copy = copy / 2;
        length += 1;
    }

    // Dynamic integer array that stores the "binary" numbers
    int* binnumber;
    binnumber = (int*)calloc(length, sizeof(int));

    if (binnumber == NULL)
    {
        cout << "Cannot allocate memory";
        exit(0);
    }

    int length_copy = length - 1;

    /*
     * 1. Store the remainder of decimal division by 2
     * 2. Divide the decimal using integer division by 2
     */
    while (decimal > 0)
    {
        *(binnumber + length_copy) = decimal % 2;
        decimal = decimal / 2;
        length_copy--;
    }

    /*
     * Print the array from above
     */
    for (int i = 0; i < length; i++)
    {
        cout << " " << *(binnumber + i) << " ";
    }

    cout << endl;

    free(binnumber);
}
