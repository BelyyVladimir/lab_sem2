using System;
using System.Linq;

class Abonent
{
    public string Name { get; set; }
    public Telephon[] Tel { get; set; }
    public string City { get; set; }

    public Abonent(string name, Telephon[] tel, string city)
    {
        Name = name;
        Tel = tel;
        City = city;
    }

    public override string ToString() => 
        $"\nИмя: {Name} | Номера: {string.Join(", ", Tel.Select(t => t.Number))} | Город: {City}";
}

class Telephon
{
    public string Number { get; set; }
    public string Oper { get; set; }
    public int Year { get; set; }

    public Telephon(string numb, string oper, int year)
    {
        Number = numb;
        Oper = oper;
        Year = year;
    }
}

class Program
{
    static void Main()
    {
        Console.Write("Количество абонентов: ");
        var abonents = new Abonent[int.Parse(Console.ReadLine())];
        
        while (true)
        {
            Console.WriteLine("\n\tМеню\n1. Заполнение\n2. Поиск по имени\n3. Поиск по оператору\n4. Поиск по номеру\n5. Выход");
            
            switch (Console.ReadLine())
            {
                case "1": Zapoln(abonents); break;
                case "2": Search(abonents, a => a.Name, "имени"); break;
                case "3": Search(abonents, a => a.Tel.Any(t => t.Oper), "оператору"); break;
                case "4": Search(abonents, a => a.Tel.Any(t => t.Number), "номеру"); break;
                case "5": return;
                default: Console.WriteLine("Неверный выбор"); break;
            }
        }
    }

    static void Zapoln(Abonent[] abonents)
    {
        for (int i = 0; i < abonents.Length; i++)
        {
            Console.Write($"\nФИО {i+1}-го абонента: ");
            string name = Console.ReadLine();

            Console.Write("Количество номеров: ");
            var tels = new Telephon[int.Parse(Console.ReadLine())];
            
            for (int j = 0; j < tels.Length; j++)
            {
                Console.Write("Номер: ");
                string num = Console.ReadLine();
                Console.Write("Год: ");
                int year = int.Parse(Console.ReadLine());
                Console.Write("Оператор: ");
                tels[j] = new Telephon(num, Console.ReadLine(), year);
            }

            Console.Write("Город: ");
            abonents[i] = new Abonent(name, tels, Console.ReadLine());
        }
    }

    static void Search(Abonent[] abonents, Func<Abonent, bool> match, string criteria)
    {
        Console.Write($"\nВведите {criteria}: ");
        string search = Console.ReadLine();
        
        var results = abonents.Where(a => match(a) && 
                          (criteria == "имени" ? a.Name == search : 
                           a.Tel.Any(t => criteria == "оператору" ? t.Oper == search : t.Number == search))).ToArray();

        Console.WriteLine(results.Length == 0 ? "Не найдено" : string.Join("", results));
    }
}
