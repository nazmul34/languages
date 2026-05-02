using System;
using System.Collections.Generic;

class VariablesScopeMutability
{
    static void MutateList(List<string> items)
    {
        items.Add("new-item");
    }

    static void Main()
    {
        int mutableCount = 1;
        const string immutableName = "Nazmul";

        var items = new List<string> { "a", "b" };
        var config = new Dictionary<string, string> { { "mode", "demo" } };

        string scopeValue;
        {
            string insideBlock = "inside";
            scopeValue = insideBlock;
        }

        MutateList(items);
        config["mode"] = "updated";
        mutableCount = mutableCount + 1;

        Console.WriteLine("Language: C#");
        Console.WriteLine($"immutableName={immutableName}");
        Console.WriteLine($"mutableCount={mutableCount}");
        Console.WriteLine($"scopeValue={scopeValue}");
        Console.WriteLine($"items=[{string.Join(", ", items)}]");
        Console.WriteLine($"config=mode:{config["mode"]}");
    }
}
