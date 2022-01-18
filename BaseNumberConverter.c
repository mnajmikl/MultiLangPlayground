/*
 * Base number converter
 * Convert decimal to binary/octal/hexadecimal number
 * 
 * Author: Mohamamd Najmi Bin Bachok
 * Version: 1.0.0
 */

#include <stdlib.h>
#include <stdio.h>

char* binary(int);
char* oct(int);
char* hex(int);

int main(int argc, char** argv)
{
	printf_s("32 = bin(0x%s)\n", binary(32));
	printf_s("32 = oct(0x%s)\n", oct(32));
	printf_s("32 = hex(0x%s)", hex(32));
	return 0;
}

/*!
 @function binary
 @param decimal The decimal number to be converted
 @result A binary number of the given decimal number
*/
char* binary(int decimal)
{
	int length = 0;
	int decimal_copy = decimal;
	char* binnumbers = "01";

	while (decimal_copy > 0)
	{
		decimal_copy = decimal_copy / 2;
		length++;
	}

	char* outnumber = (char*)calloc(length, sizeof(char*));
	
	if (outnumber == NULL)
	{
		printf_s("Cannot allocate memory");
		exit(0);
	}

	int length_copy = length - 1;

	while (decimal > 0)
	{
		*(outnumber + length_copy) = binnumbers[decimal % 2];
		decimal = decimal / 2;
		length_copy--;
	}

	return outnumber;
}

/*!
 @function oct
 @param decimal The decimal number to be converted
 @result A octal number of the given decimal number
*/
char* oct(int decimal)
{
	int length = 0;
	int decimal_copy = decimal;
	char* octnumbers = "01234567";

	while (decimal_copy > 0)
	{
		decimal_copy = decimal_copy / 8;
		length++;
	}

	char* outnumber = (char*)calloc(length, sizeof(char*));

	if (outnumber == NULL)
	{
		printf_s("Cannot allocate memory");
		exit(0);
	}

	int length_copy = length - 1;

	while (decimal > 0)
	{
		*(outnumber + length_copy) = octnumbers[decimal % 8];
		decimal = decimal / 8;
		length_copy--;
	}

	return outnumber;
}

/*!
 @function hex
 @param decimal The decimal number to be converted
 @result A hexadecimal number of the given decimal number
*/
char* hex(int decimal)
{
	int length = 0;
	int decimal_copy = decimal;
	char* hexnumbers = "0123456789ABCDEF";

	while (decimal_copy > 0)
	{
		decimal_copy = decimal_copy / 16;
		length++;
	}

	char* outnumber = (char*)calloc(length, sizeof(char*));

	if (outnumber == NULL)
	{
		printf_s("Cannot allocate memory");
		exit(0);
	}

	int length_copy = length - 1;

	while (decimal > 0)
	{
		*(outnumber + length_copy) = hexnumbers[decimal % 16];
		decimal = decimal / 16;
		length_copy--;
	}

	return outnumber;
}