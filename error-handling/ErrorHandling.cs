using System;
using System.Collections.Generic;

class InvalidAgeException : Exception
{
    public InvalidAgeException(string message) : base(message) { }
}

class ConfigException : Exception
{
    public ConfigException(string message) : base(message) { }
}

class ErrorHandling
{
    static int ParseAge(string text)
    {
        try
        {
            int age = int.Parse(text);
            if (age < 0)
            {
                throw new InvalidAgeException("Age cannot be negative");
            }
            return age;
        }
        catch (FormatException ex)
        {
            throw new InvalidAgeException($"Age must be a number: {text}", ex);
        }
    }

    static string LoadConfig(Dictionary<string, string> data)
    {
        if (!data.ContainsKey("mode"))
        {
            throw new ConfigException("Missing 'mode' in config");
        }
        return data["mode"];
    }

    static void CheckedVsUncheckedNote()
    {
        Console.WriteLine("C# note: no checked exceptions; all exceptions are runtime.");
    }

    static void Main()
    {
        Console.WriteLine("Language: C#");

        try
        {
            Console.WriteLine($"Parsed age: {ParseAge("21")}");
            Console.WriteLine($"Parsed age: {ParseAge("oops")}");
        }
        catch (InvalidAgeException ex)
        {
            Console.WriteLine($"Caught custom exception: {ex.Message}");
        }
        finally
        {
            Console.WriteLine("Finally block: cleanup/logging runs always");
        }

        try
        {
            string mode = LoadConfig(new Dictionary<string, string>());
            Console.WriteLine($"Mode: {mode}");
        }
        catch (ConfigException ex)
        {
            Console.WriteLine($"Caught runtime-style custom exception: {ex.Message}");
        }

        CheckedVsUncheckedNote();
    }
}
