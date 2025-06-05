using System;
using System.Linq;
using System.Collections.Generic;

class Telephon
{
    public string Number { get; set; }
    public string Name { get; set; }
    public string Operator { get; set; }
    
    public Telephon(string number, string name, string oper)
    {
        Number = number;
        Name = name;
        Operator = oper;
    }
}

class Program
{
    static void Main()
    {
        var telephons = new List<Telephon>
        {
            new Telephon("89888888888", "Vanya", "MTS"),
            new Telephon("89888888888", "Vova", "tele2"),
            new Telephon("89888888888", "Ilik", "tele2"),
            new Telephon("89888888888", "Misha", "beeline"),
            new Telephon("89888888888", "Egor", "MTS")
        };

        var operatorStats = telephons
            .GroupBy(t => t.Operator)
            .ToDictionary(g => g.Key, g => g.Count());

        Console.WriteLine("Статистика операторов:");
        foreach (var stat in operatorStats)
        {
            Console.WriteLine($"{stat.Key}: {stat.Value}");
        }
    }
}
