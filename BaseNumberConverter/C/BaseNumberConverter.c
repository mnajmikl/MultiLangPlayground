/*
 * Base number converter
 * Convert decimal to binary/octal/hexadecimal number
 * 
 * Author: Mohammad Najmi Bin Bachok
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <stdio.h>

char* basenumber(unsigned int, unsigned int, const char*);
char* binary(unsigned int);
char* octal(unsigned int);
char* hexadecimal(unsigned int);

int main(int argc, char** argv)
{
	printf_s("255 = binary(0x%s)\n", binary(255));
	printf_s("255 = octal(0x%s)\n", octal(255));
	printf_s("255 = hexdecimal(0x%s)", hexadecimal(255));
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

	char* outnumber = (char*)calloc(length, sizeof(char));

	if (outnumber == NULL)
	{
		printf_s("Cannot allocate memory");
		return '\0';
	}

	length--;

	while (decimal_copy > 0)
	{
		*(outnumber + length) = numbers[decimal_copy % base];
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
	return basenumber(decimal, 16, "0123456789ABCDEF");
}
