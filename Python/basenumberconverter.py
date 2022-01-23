"""
# Generate decimal to binary/octal/hexadecimal number
# Author: Mohammad Najmi
# Version: 1.0.0
"""

def basenumberconverter(dec, base, numbers):
    """
    Convert decimal number to number of given base

    Parameters:
    dec (int)  : Decimal to convert
    base (int) : Base of the number to convert into
    numbers (str): Numbers of the given base

    Returns:
    str: The converted number in given base
    """

    length = 0
    dec_copy = dec
    outnumber = ""

    while dec > 0:
        dec = dec // base
        length = length + 1

    while dec_copy > 0:
        outnumber = outnumber + numbers[dec_copy % base]
        dec_copy = dec_copy // base
        length = length - 1

    return outnumber[::-1]

def binary(dec):
    """
    Convert decimal number to binary

    Parameters:
    dec (int) : Decimal to convert

    Returns:
    str: The binary number of the given decimal
    """
    return basenumberconverter(dec, 2, "01")

def octal(dec):
    """
    Convert decimal number to octal

    Parameters:
    dec (int) : Decimal to convert

    Returns:
    str: The octal number of the given decimal
    """
    return basenumberconverter(dec, 8, "01234567")

def hexadecimal(dec):
    """
    Convert decimal number to hexadecimal

    Parameters:
    dec (int) : Decimal to convert

    Returns:
    str: The hexadecimal number of the given decimal
    """
    return "0x" + basenumberconverter(dec, 16, "0123456789ABCDEF")
