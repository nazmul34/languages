using System;
using System.Collections.Generic;

class SyntaxSimplicity
{
    static bool IsEven(int n)
    {
        return n % 2 == 0;
    }

    static void Main()
    {
        var numbers = new List<int> { 5, 1, 4, 2, 3 };
        var evenSquares = new List<int>();

        foreach (var n in numbers)
        {
            if (IsEven(n))
            {
                evenSquares.Add(n * n);
            }
        }

        var total = 0;
        foreach (var value in evenSquares)
        {
            total += value;
        }

        Console.WriteLine("Language: C#");
        Console.WriteLine($"Input: [{string.Join(", ", numbers)}]");
        Console.WriteLine($"Even squares: [{string.Join(", ", evenSquares)}]");
        Console.WriteLine($"Total: {total}");
    }
}
