using System;
using System.Collections.Generic;
using System.Threading;
using System.Threading.Tasks;

class ConcurrencyAsync
{
    // --- Threads ---
    static void RunThreads()
    {
        Console.WriteLine("\n-- Threads --");
        var t1 = new Thread(() => Console.WriteLine("Thread A running"));
        var t2 = new Thread(() => Console.WriteLine("Thread B running"));
        t1.Start();
        t2.Start();
        t1.Join();
        t2.Join();
    }

    // --- async/await ---
    static async Task<string> FetchDataAsync(string name, int delayMs)
    {
        await Task.Delay(delayMs);   // non-blocking wait
        return $"Data from '{name}'";
    }

    static async Task RunAsyncAwait()
    {
        Console.WriteLine("\n-- async/await --");

        // Sequential
        string a = await FetchDataAsync("source-A", 100);
        string b = await FetchDataAsync("source-B", 100);
        Console.WriteLine($"Sequential: {a} | {b}");

        // Parallel: Task.WhenAll runs tasks concurrently
        string[] results = await Task.WhenAll(
            FetchDataAsync("source-X", 200),
            FetchDataAsync("source-Y", 100),
            FetchDataAsync("source-Z", 50)
        );
        Console.WriteLine("Task.WhenAll: " + string.Join(", ", results));
    }

    // --- Parallel execution (CPU-bound work) ---
    static void RunParallel()
    {
        Console.WriteLine("\n-- Parallel (CPU-bound) --");

        // Parallel.For uses thread pool for data parallelism
        int[] squares = new int[5];
        Parallel.For(0, 5, i => squares[i] = i * i);
        Console.WriteLine("Parallel.For squares: " + string.Join(", ", squares));

        // Task.Run offloads CPU work off the calling thread
        var task = Task.Run(() =>
        {
            long sum = 0;
            for (int i = 0; i < 1_000_000; i++) sum += i;
            return sum;
        });
        Console.WriteLine("Task.Run sum: " + task.Result);
    }

    static async Task Main()
    {
        Console.WriteLine("Language: C#");
        RunThreads();
        await RunAsyncAwait();
        RunParallel();
    }
}
