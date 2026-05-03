using System;
using System.Collections.Generic;
using System.Diagnostics;

class BigObject
{
    public int[] Data;

    public BigObject(int size)
    {
        Data = new int[size];
    }
}

class MemoryManagement
{
    static void LifetimeDemo()
    {
        Console.WriteLine("\n-- Object lifetime --");
        BigObject obj = new BigObject(100_000);
        Console.WriteLine($"Object created, len(data)= {obj.Data.Length}");
        obj = null!;
        Console.WriteLine("Reference cleared; object is eligible for GC");
    }

    static void GcDemo()
    {
        Console.WriteLine("\n-- Garbage collection --");
        long before = GC.GetTotalMemory(forceFullCollection: false);
        Console.WriteLine($"Managed memory before: {before / (1024 * 1024)} MB");

        List<BigObject> tmp = new();
        for (int i = 0; i < 200; i++) tmp.Add(new BigObject(20_000));
        tmp = null!;

        GC.Collect();
        GC.WaitForPendingFinalizers();
        long after = GC.GetTotalMemory(forceFullCollection: true);
        Console.WriteLine($"Managed memory after:  {after / (1024 * 1024)} MB");
    }

    static void PerformanceTradeoff()
    {
        Console.WriteLine("\n-- Performance tradeoff --");
        var sw = Stopwatch.StartNew();
        List<object> list = new();
        for (int i = 0; i < 500_000; i++) list.Add(new object());
        sw.Stop();
        Console.WriteLine($"Allocated 500000 objects in {sw.ElapsedMilliseconds} ms");
        Console.WriteLine("Tradeoff: GC improves safety/productivity but can add pauses");
    }

    static void Main()
    {
        Console.WriteLine("Language: C#");
        LifetimeDemo();
        GcDemo();
        PerformanceTradeoff();
    }
}
