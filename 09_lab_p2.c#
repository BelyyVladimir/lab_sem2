using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        var words = new List<string> { "арбуз", "дыня", "аист", "Окно" };
        
        Func<List<string>, List<string>> filterWords = list => 
            list.Where(word => word.StartsWith("а", StringComparison.OrdinalIgnoreCase))
                .ToList();
        
        var result = filterWords(words);
        
        Console.WriteLine("Слова, начинающиеся на 'а':");
        result.ForEach(Console.WriteLine);
    }
}
