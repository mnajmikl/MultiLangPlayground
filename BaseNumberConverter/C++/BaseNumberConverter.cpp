/*
 * Base number converter
 * Convert decimal to binary/octal/hexadecimal number
 *
 * Author: Mohammad Najmi Bin Bachok
 * Version: 1.0.0
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*!
 @function basenumber
 @param decimal: The decimal number to be converted
 @param base: The base of the number
 @param numbers: The numbers in the base number given
 @result A number in the specified base of the given decimal number
*/
std::string basenumber(unsigned int decimal, unsigned int base, const std::string numbers)
{
    std::vector<std::string> binnumber;
    while (decimal > 0)
    {
        binnumber.push_back(numbers.substr((decimal%base),1));
        decimal = decimal / base;
    }
    std::string binstr;
    std::reverse(std::begin(binnumber), std::end(binnumber));
    for (auto s : binnumber)
        binstr += s;
    return binstr;
}

/*!
 @function binary
 @param decimal: The decimal number to be converted
 @result A binary number of the given decimal number
*/
std::string binary(unsigned int decimal)
{
    return basenumber(decimal, 2, "01");
}

/*!
 @function octal
 @param decimal: The decimal number to be converted
 @result A octal number of the given decimal number
*/
std::string octal(unsigned int decimal)
{
    return basenumber(decimal, 8, "01234567");
}

/*!
 @function hexadecimal
 @param decimal: The decimal number to be converted
 @result A hexadecimal number of the given decimal number
*/
std::string hexadecimal(unsigned int decimal)
{
    return  basenumber(decimal, 16, "0123456789ABCDEF");
}

int main()
{
    std::string b = binary(99);
    std::string o = octal(99);
    std::string h = hexadecimal(99);
    std::cout << "99 = binary(b" << b << ")" << std::endl;
    std::cout << "99 = octal(o" << o << ")" << std::endl;
    std::cout << "99 = hexdecimal(0x" << h << ")" << std::endl;
    return 0;
}

