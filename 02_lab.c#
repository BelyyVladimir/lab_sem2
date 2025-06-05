using System;

class Figura { public string Name { get; set; } }
interface Formula { double Perimetr(); double Plochad(); }

class Circle : Figura, Formula
{
    public double Radius;
    public double Perimetr() => 2 * 3.14 * Radius;
    public double Plochad() => 3.14 * Radius * Radius;
}

class Square : Figura, Formula
{
    public double Storona;
    public double Perimetr() => 4 * Storona;
    public double Plochad() => Storona * Storona;
}

class Triangle : Figura, Formula
{
    public double Rebro;
    public double Perimetr() => 3 * Rebro;
    public double Plochad() => Math.Sqrt(3) * Rebro * Rebro / 4;
}

class Program
{
    static void Main()
    {
        var circle = new Circle { Name = "Окружность", Radius = GetInput("радиус окружности") };
        var square = new Square { Name = "Квадрат", Storona = GetInput("сторону квадрата") };
        var triangle = new Triangle { Name = "Треугольник", Rebro = GetInput("сторону треугольника") };

        PrintResults(circle);
        PrintResults(square);
        PrintResults(triangle);
    }

    static double GetInput(string prompt)
    {
        Console.WriteLine($"Введите {prompt}");
        return double.Parse(Console.ReadLine());
    }

    static void PrintResults(Formula fig)
    {
        Console.WriteLine($"\nФигура: {(fig as Figura).Name}");
        Console.WriteLine($"Периметр: {fig.Perimetr()}");
        Console.WriteLine($"Площадь: {fig.Plochad()}");
    }
}
