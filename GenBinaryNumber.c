#include <stdlib.h>
#include <stdio.h>

char* binnum(int);

int main(int argc, char** argv)
{
    printf_s("132 = %s\n", binnum(132));
    printf_s("133 = %s\n", binnum(133));
    return 0;
}

char* binnum(int decimal)
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
    char* binnumber;
    binnumber = (char*) calloc(length, sizeof(char*));

    if (binnumber == NULL)
    {
        printf_s("Cannot allocate memory");
        exit(0);
    }

    int length_copy = length - 1;

    /*
     * 1. Store the remainder of decimal division by 2
     * 2. Divide the decimal using integer division by 2
     */
    while (decimal > 0)
    {
        switch (decimal % 2)
        {
            case 0:
                *(binnumber + length_copy) = '0';
                break;
            case 1:
                *(binnumber + length_copy) = '1';
                break;
        }
        decimal = decimal / 2;
        length_copy--;
    }
	return binnumber;
}
