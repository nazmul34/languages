using System;
using System.Collections.Generic;
using System.Linq;

class SortingSearching
{
    // --- Manual algorithms ---

    static int[] BubbleSort(int[] input)
    {
        int[] arr = (int[])input.Clone();
        int n = arr.Length;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    (arr[j], arr[j + 1]) = (arr[j + 1], arr[j]);
                }
            }
        }
        return arr;
    }

    static int[] MergeSort(int[] arr)
    {
        if (arr.Length <= 1) return (int[])arr.Clone();
        int mid = arr.Length / 2;
        int[] left = MergeSort(arr[..mid]);
        int[] right = MergeSort(arr[mid..]);
        return Merge(left, right);
    }

    static int[] Merge(int[] left, int[] right)
    {
        int[] result = new int[left.Length + right.Length];
        int i = 0, j = 0, k = 0;
        while (i < left.Length && j < right.Length)
            result[k++] = left[i] <= right[j] ? left[i++] : right[j++];
        while (i < left.Length) result[k++] = left[i++];
        while (j < right.Length) result[k++] = right[j++];
        return result;
    }

    static int BinarySearch(int[] arr, int target)
    {
        int lo = 0, hi = arr.Length - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return -1;
    }

    static void Main()
    {
        Console.WriteLine("Language: C#");
        int[] unsorted = { 64, 34, 25, 12, 22, 11, 90 };
        Console.WriteLine($"Original:              [{string.Join(", ", unsorted)}]");

        // Manual sorts
        Console.WriteLine($"Bubble sort:           [{string.Join(", ", BubbleSort(unsorted))}]");
        Console.WriteLine($"Merge sort:            [{string.Join(", ", MergeSort(unsorted))}]");

        // Built-in sort (introsort)
        int[] builtIn = (int[])unsorted.Clone();
        Array.Sort(builtIn);
        Console.WriteLine($"Array.Sort():          [{string.Join(", ", builtIn)}]");

        // LINQ OrderBy
        var linq = unsorted.OrderBy(x => x).ToArray();
        Console.WriteLine($"LINQ OrderBy():        [{string.Join(", ", linq)}]");

        // Manual binary search
        int[] sorted = MergeSort(unsorted);
        Console.WriteLine($"Manual binary search for 25: index {BinarySearch(sorted, 25)}");

        // Built-in binary search
        Console.WriteLine($"Array.BinarySearch() for 25: index {Array.BinarySearch(sorted, 25)}");

        // LINQ search
        Console.WriteLine($"LINQ FirstOrDefault index:   {Array.IndexOf(sorted, 25)}");
    }
}
