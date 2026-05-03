using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;

class FunctionalProgramming
{
    static void Main()
    {
        Console.WriteLine("Language: C#");

        var numbers = new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        // --- Lambdas ---
        Func<int, int> doubleIt = x => x * 2;
        Func<int, bool> isEven = x => x % 2 == 0;
        Func<int, int, int> add = (a, b) => a + b;
        Console.WriteLine($"Lambda double(5):   {doubleIt(5)}");

        // --- map (LINQ Select) ---
        var doubled = numbers.Select(doubleIt).ToList();
        Console.WriteLine($"Select/map (double):  [{string.Join(", ", doubled)}]");

        // --- filter (LINQ Where) ---
        var evens = numbers.Where(isEven).ToList();
        Console.WriteLine($"Where/filter (evens): [{string.Join(", ", evens)}]");

        // --- reduce (LINQ Aggregate) ---
        int total = numbers.Aggregate(0, add);
        Console.WriteLine($"Aggregate/reduce:     {total}");

        // --- Composed pipeline (method chaining) ---
        int result = numbers
            .Where(isEven)
            .Select(doubleIt)
            .Aggregate(0, add);
        Console.WriteLine($"filter→map→reduce:   {result}");

        // --- Immutability patterns ---
        // ReadOnlyCollection wraps a list to prevent mutation
        var original = new ReadOnlyCollection<int>(new List<int> { 1, 2, 3 });
        // original.Add(4) would throw NotSupportedException
        var extended = original.Append(4).ToList(); // new list
        Console.WriteLine($"ReadOnly original:    [{string.Join(", ", original)}]");
        Console.WriteLine($"Extended (new list):  [{string.Join(", ", extended)}]");

        // with expressions on records for immutable updates
        Console.WriteLine("Original numbers unchanged: " + string.Join(", ", numbers));
    }
}
