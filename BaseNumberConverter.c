/*
 * Base number converter
 * Convert decimal to binary/octal/hexadecimal number
 * 
 * Author: Mohamamd Najmi Bin Bachok
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <stdio.h>

unsigned int getnumberlength(unsigned int, unsigned int);
const char* getbasenumber(unsigned int, unsigned int, 
								unsigned int, const char*);
const char* binary(unsigned int);
const char* oct(unsigned int);
const char* hex(unsigned int);

int main(int argc, char** argv)
{
	printf_s("255 = bin(0x%s)\n", binary(255));
	printf_s("255 = oct(0x%s)\n", oct(255));
	printf_s("255 = hex(0x%s)", hex(255));
	return 0;
}

/*!
 @function getnumberlength
 @param decimal The decimal number to be converted
 @param base The base of the number
 @result A binary number of the given decimal number
*/
unsigned int getnumberlength(unsigned int decimal, unsigned int base)
{
	unsigned int length = 0;
	while (decimal > 0)
	{
		decimal = decimal / base;
		length++;
	}
	return length;
}

/*!
 @function getbasenumber
 @param decimal The decimal number to be converted
 @param base The base of the number
 @param length The length  of the base number
 @param numbers The numbers in the base number given
 @result A binary number of the given decimal number
*/
const char* getbasenumber(unsigned int decimal, unsigned int base,
							unsigned int length, const char* numbers)
{
	char* outnumber = (char*)calloc(length, sizeof(char));

	if (outnumber == NULL)
	{
		printf_s("Cannot allocate memory");
		return '\0';
	}

	int length_copy = length - 1;

	while (decimal > 0)
	{
		*(outnumber + length_copy) = numbers[decimal % base];
		decimal = decimal / base;
		length_copy--;
	}

	return outnumber;
}

/*!
 @function binary
 @param decimal The decimal number to be converted
 @result A binary number of the given decimal number
*/
const char* binary(unsigned int decimal)
{
	unsigned int length = getnumberlength(decimal, 2);
	return getbasenumber(decimal, 2, length, "01");
}

/*!
 @function oct
 @param decimal The decimal number to be converted
 @result A octal number of the given decimal number
*/
const char* oct(unsigned int decimal)
{
	unsigned int length = getnumberlength(decimal, 8);
	return getbasenumber(decimal, 8, length, "01234567");
}

/*!
 @function hex
 @param decimal The decimal number to be converted
 @result A hexadecimal number of the given decimal number
*/
const char* hex(unsigned int decimal)
{
	unsigned int length = getnumberlength(decimal, 16);
	return getbasenumber(decimal, 16, length, "0123456789ABCDEF");
}