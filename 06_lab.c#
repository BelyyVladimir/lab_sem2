using System;

class Calculator
{
    public int X { get; }
    public int Y { get; }
    
    public Calculator(int x, int y)
    {
        X = x;
        Y = y;
    }
    
    public int Add() => X + Y;
    public int Subtract() => X - Y;
    public int Multiply() => X * Y;
    public int Divide() => Y == 0 ? throw new DivideByZeroException("Делить на ноль нельзя") : X / Y;
}

delegate int MathOperation();

class Program
{
    static int AddThenSubtractY(Calculator calc) => calc.Add() - calc.Y;
    static int MultiplyAddSubY(Calculator calc) => AddThenSubtractY(calc) * calc.Y;
    static int DivideThenAddY(Calculator calc) => calc.Divide() + calc.Y;
    static int MultiplyDivideAddY(Calculator calc) => DivideThenAddY(calc) * calc.Y;

    static void Main()
    {
        try
        {
            Console.WriteLine("Введите два числа:");
            int x = int.Parse(Console.ReadLine());
            int y = int.Parse(Console.ReadLine());

            var calc1 = new Calculator(x, y);
            var calc2 = new Calculator(x, y);

            // Создаем и наполняем делегаты
            MathOperation op1 = calc1.Add;
            op1 += () => AddThenSubtractY(calc1);
            op1 += () => MultiplyAddSubY(calc1);

            MathOperation op2 = calc2.Divide;
            op2 += () => DivideThenAddY(calc2);
            op2 += () => MultiplyDivideAddY(calc2);

            // Выполняем операции и выводим результаты
            ExecuteAndPrint("Результаты для первой цепочки операций:", op1);
            ExecuteAndPrint("\nРезультаты для второй цепочки операций:", op2);
        }
        catch (FormatException)
        {
            Console.WriteLine("Ошибка: введены некорректные числа");
        }
        catch (DivideByZeroException ex)
        {
            Console.WriteLine($"Ошибка: {ex.Message}");
        }
    }

    static void ExecuteAndPrint(string message, MathOperation operation)
    {
        Console.WriteLine(message);
        foreach (MathOperation op in operation.GetInvocationList())
        {
            try
            {
                Console.WriteLine(op());
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка при выполнении операции: {ex.Message}");
            }
        }
    }
}
