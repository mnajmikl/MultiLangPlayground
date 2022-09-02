///
// BinaryNumber.cpp
//
// Added C++ 20 new methods like std::span() to iterate dynamically created arrays
//
///

#include <iostream>
#include <string>
#include <span>

///
//  Function std::string getbinarynumber(unsigned int)
//  This will return a binary string for the given number
///
std::string getbinarynumber(unsigned int decimal)
{
    int length = 0;
    int copy = decimal;
    ///
    // Find the length of the array to store the "binary"
    // numbers (remainders from division by 2)
    ///
    while (copy > 0)
    {
        copy = copy / 2;
        length += 1;
    }
    // Dynamic integer array that stores the "binary" numbers
    int *binnumber = new int[length]();
    std::fill_n(binnumber, length, 0);
    int length_copy = length - 1;
    ///
    // 1. Store the remainder of decimal division by 2
    // 2. Divide the decimal using integer division by 2
    // The result is the reversed version of the binary number
    ///
    while (decimal > 0)
    {
        binnumber[length_copy] = decimal % 2;
        decimal = decimal / 2;
        length_copy--;
    }
    std::string binstr;
    for (int i : std::span(binnumber, length))
        binstr += std::to_string(i);
    delete[] binnumber;
    return binstr;
}

int main()
{
    std::cout<<"132 in binary is: " << getbinarynumber(132);
    return 0;
}

