using System;
using System.Collections.Generic;

class CollectionsDataStructures
{
    static void Main()
    {
        Console.WriteLine("Language: C#");

        // Array
        int[] numbersArray = { 10, 20, 30 };
        Console.WriteLine($"Array: [{string.Join(", ", numbersArray)}]");

        // List
        List<int> numbersList = new() { 1, 2, 3 };
        numbersList.Add(4);
        Console.WriteLine($"List: [{string.Join(", ", numbersList)}]");

        // Dictionary (map)
        Dictionary<string, int> scores = new()
        {
            ["alice"] = 95,
            ["bob"] = 88,
            ["carol"] = 91
        };
        Console.WriteLine("Dictionary:");
        foreach (var pair in scores)
        {
            Console.WriteLine($"  {pair.Key}: {pair.Value}");
        }

        // Set
        HashSet<int> uniqueValues = new() { 1, 2, 2, 3 };
        uniqueValues.Add(4);
        Console.WriteLine($"Set: [{string.Join(", ", uniqueValues)}]");

        // Queue (FIFO)
        Queue<string> queue = new();
        queue.Enqueue("first");
        queue.Enqueue("second");
        queue.Enqueue("third");
        string removedFromQueue = queue.Dequeue();
        Console.WriteLine($"Queue removed: {removedFromQueue} Remaining: [{string.Join(", ", queue)}]");

        // Stack (LIFO)
        Stack<string> stack = new();
        stack.Push("bottom");
        stack.Push("middle");
        stack.Push("top");
        string removedFromStack = stack.Pop();
        Console.WriteLine($"Stack removed: {removedFromStack} Remaining: [{string.Join(", ", stack)}]");
    }
}
