using System;

public static class Program
{
    public static void Main()
    {
        Console.WriteLine("33 in hexadecimal is {0}", 
            BaseNumberConverter.Hexadecimal(33));
        Console.WriteLine("33 in octal is {0}", 
            BaseNumberConverter.Octal(33));
        Console.WriteLine("33 in binary is {0}", 
            BaseNumberConverter.Binary(33));
    }
}

