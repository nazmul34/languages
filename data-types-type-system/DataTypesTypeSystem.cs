using System;
using System.Collections.Generic;

class DataTypesTypeSystem
{
    static void Main()
    {
        int age = 28;
        double temperature = 36.7;
        string name = "Nazmul";
        bool isActive = true;
        var tags = new List<string> { "csharp", "types", "demo" };
        var scores = new Dictionary<string, int> { { "math", 90 }, { "science", 88 } };
        string? middleName = null;

        string convertedAge = age.ToString();
        int parsedNumber = int.Parse("42");

        Console.WriteLine("Language: C#");
        Console.WriteLine($"age={age} (int)");
        Console.WriteLine($"temperature={temperature} (double)");
        Console.WriteLine($"name={name} (string)");
        Console.WriteLine($"isActive={isActive} (bool)");
        Console.WriteLine($"tags=[{string.Join(", ", tags)}] (List<string>)");
        Console.WriteLine($"scores=math:{scores["math"]}, science:{scores["science"]} (Dictionary<string, int>)");
        Console.WriteLine($"middleName={middleName} (string?)");
        Console.WriteLine($"convertedAge={convertedAge} (string)");
        Console.WriteLine($"parsedNumber={parsedNumber} (int)");
    }
}
