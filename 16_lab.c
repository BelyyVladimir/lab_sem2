using System;

class Program
{
    static bool IsPalindrome(int number)
    {
        if (number < 0) return false;
        
        int original = number;
        int reversed = 0;
        
        while (number > 0)
        {
            reversed = reversed * 10 + number % 10;
            number /= 10;
        }
        
        return reversed == original;
    }

    static void Main()
    {
        int[] numbers = { 1, 555, 566, 121, 1221, 23 };
        
        Console.WriteLine("Palindromes found:");
        foreach (int num in numbers)
        {
            if (IsPalindrome(num))
            {
                Console.WriteLine(num);
            }
        }
    }
}
