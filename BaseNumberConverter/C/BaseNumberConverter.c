/*
 * Base number converter
 * Convert decimal to binary/octal/hexadecimal number
 *
 * Author: Mohammad Najmi Bin Bachok
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* basenumber(unsigned int, unsigned int, const char*);
char* binary(unsigned int);
char* octal(unsigned int);
char* hexadecimal(unsigned int);

int main()
{
    char* b = binary(255);
    char* o = octal(255);
    char* h = hexadecimal(255);
	printf("255 = binary(0x%s)\n", b);
	printf("255 = octal(0x%s)\n", o);
	printf("255 = hexdecimal(0x%s)\n", h);
	free(b);
	free(o);
	free(h);
	return 0;
}

/*!
 @function basenumber
 @param decimal: The decimal number to be converted
 @param base: The base of the number
 @param numbers: The numbers in the base number given
 @result A number in the specified base of the given decimal number
*/
char* basenumber(unsigned int decimal, unsigned int base, const char* numbers)
{
	unsigned int length = 0;
	unsigned int decimal_copy = decimal;
	while (decimal > 0)
	{
		decimal = decimal / base;
		length++;
	}
	char* outnumber = calloc(length + 1, sizeof(char));

	if (outnumber == NULL) return NULL;
	length--;
	while (decimal_copy > 0)
	{
		outnumber[length] = numbers[decimal_copy % base];
		decimal_copy = decimal_copy / base;
		length--;
	}
	return outnumber;
}

/*!
 @function binary
 @param decimal: The decimal number to be converted
 @result A binary number of the given decimal number
*/
char* binary(unsigned int decimal)
{
    return basenumber(decimal, 2, "01");
}

/*!
 @function octal
 @param decimal: The decimal number to be converted
 @result A octal number of the given decimal number
*/
char* octal(unsigned int decimal)
{
	return basenumber(decimal, 8, "01234567");
}

/*!
 @function hexadecimal
 @param decimal: The decimal number to be converted
 @result A hexadecimal number of the given decimal number
*/
char* hexadecimal(unsigned int decimal)
{
	return  basenumber(decimal, 16, "0123456789ABCDEF");
}
