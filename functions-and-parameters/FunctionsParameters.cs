using System;

class FunctionsParameters
{
    static string Greet(string name, string prefix = "Hello")
    {
        return $"{prefix}, {name}!";
    }

    // Overloading example
    static int Add(int a)
    {
        return Add(a, 0);
    }

    static int Add(int a, int b)
    {
        return a + b;
    }

    static int ApplyOperation(int a, int b, Func<int, int, int> operation)
    {
        return operation(a, b);
    }

    static void Main()
    {
        // Default parameter
        Console.WriteLine(Greet("Nazmul"));

        // Named parameter
        Console.WriteLine(Greet(name: "Nazmul", prefix: "Hi"));

        Console.WriteLine(Add(10));
        Console.WriteLine(Add(10, 5));

        // First-class function: a lambda can be stored in a variable and passed to another function.
        Func<int, int, int> multiply = (x, y) => x * y;
        Console.WriteLine(ApplyOperation(4, 3, multiply));
    }
}
