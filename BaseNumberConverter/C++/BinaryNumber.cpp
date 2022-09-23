///
// BinaryNumber.cpp
//
// This program demonstrates the use of std::vector and its reverse iteration
// to create binary number string
//
///

#include <iostream>
#include <string>
#include <vector>

///
//  Function std::string getbinarynumber(unsigned int)
//  This will return a binary string for the given number
///
std::string getbinarynumber(unsigned int decimal)
{
    // Find the length of the array to store the "binary"
    // numbers (remainders from division by 2)
    // 1. Store the remainder of decimal division by 2
    // 2. Divide the decimal using integer division by 2
    // The result is the reversed version of the binary number
    std::vector<int> binnumber;
    while (decimal > 0)
    {
        binnumber.push_back(decimal % 2);
        decimal = decimal / 2;
    }
    std::string binstr;
    for (auto i = binnumber.rbegin(); i != binnumber.rend(); ++i)
        binstr += std::to_string(*i);
    return binstr;
}

int main()
{
    std::cout<<"132 in binary is: " << getbinarynumber(132);
    std::cout<<"\n69 in binary is: " << getbinarynumber(69);
    return 0;
}

