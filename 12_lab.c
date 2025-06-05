using System;
using System.IO;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        string input = @"C:\Users\DaniilMS\Desktop\input.txt";
        string output = @"C:\Users\DaniilMS\Desktop\output.txt";

        var lines = File.ReadAllLines(input);
        var filteredLines = new List<string>();

        foreach (var line in lines)
        {
            string currentNumber = "";

            foreach (var c in line)
            {
                if (char.IsDigit(c))
                {
                    currentNumber += c;
                }
                else if (currentNumber.Length > 0)
                {
                    if (int.Parse(currentNumber) % 2 == 0)
                    {
                        filteredLines.Add(line);
                        break;
                    }
                    currentNumber = "";
                }
            }

            if (currentNumber.Length > 0 && int.Parse(currentNumber) % 2 == 0)
            {
                filteredLines.Add(line);
            }
        }
        File.WriteAllLines(output, filteredLines);
    }
}
