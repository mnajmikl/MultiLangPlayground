/*
 *  Base Number Converter
 *
 * @version 1.0.0
 * @author Mohammad Najmi
 */

public class BaseNumberConverter
{
    /// <summary>
    /// Method to convert decimal to the specified base number
    /// </summary>
    /// <param name="dec">The decimal number</param>
    /// <param name="numberbase">The base of the number to convert</param>
    /// <param name="numbers">The numbers used in that base number system</param>
    /// <returns>A string of the number in the given base</returns>
    private static string BaseNumber(uint dec, uint numberbase, string numbers)
    {
        uint length = 0;
        uint dec_copy = dec;

        while (dec > 0)
        {
            dec /= numberbase;
            length++;
        }

        string outnumber = "";

        length--;

        while (dec_copy > 0)
        {
            outnumber += numbers.Substring((int)dec_copy % (int)numberbase, 1);
            dec_copy /= numberbase;
            length--;
        }

        char[] charArr = outnumber.ToCharArray();
        Array.Reverse(charArr);

        return new string(charArr);
    }

    /// <summary>
    /// Convert decimal number to binary
    /// </summary>
    /// <param name="dec">The decimal number</param>
    /// <returns>Binary number of the given decimal</returns>
    public static string Binary(uint dec)
    {
        return BaseNumber(dec, 2, "01");
    }

    /// <summary>
    /// Convert decimal number to octal
    /// </summary>
    /// <param name="dec">The decimal number</param>
    /// <returns>Octal number of the given decimal</returns>
    public static string Octal(uint dec)
    {
        return BaseNumber(dec, 8, "01234567");
    }

    /// <summary>
    /// Convert decimal number to hexadecimal
    /// </summary>
    /// <param name="dec">The decimal number</param>
    /// <returns>Hexadecimal number of the given decimal</returns>
    public static string Hexadecimal(uint dec)
    {
        return BaseNumber(dec, 16, "0123456789ABCDEF");
    }
}
