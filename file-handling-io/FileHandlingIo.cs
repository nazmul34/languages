using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.Json;

class FileHandlingIo
{
    static void Main()
    {
        Console.WriteLine("Language: C#");

        string baseDir = AppContext.BaseDirectory;
        string dataDir = Path.Combine(baseDir, "data");
        Directory.CreateDirectory(dataDir);

        string textPath = Path.Combine(dataDir, "sample.txt");
        string jsonPath = Path.Combine(dataDir, "sample.json");
        string csvPath = Path.Combine(dataDir, "sample.csv");

        // Buffered text write/read.
        using (var writer = new StreamWriter(textPath, false, new UTF8Encoding(false), bufferSize: 8192))
        {
            writer.WriteLine("line-1");
            writer.WriteLine("line-2");
        }

        using (var reader = new StreamReader(textPath, Encoding.UTF8, detectEncodingFromByteOrderMarks: true, bufferSize: 8192))
        {
            Console.WriteLine("Text read:");
            Console.WriteLine(reader.ReadToEnd().Trim());
        }

        // JSON write/read.
        var payload = new
        {
            name = "Nazmul",
            skills = new[] { "python", "javascript", "java", "csharp", "cpp" },
            active = true
        };

        string json = JsonSerializer.Serialize(payload, new JsonSerializerOptions { WriteIndented = true });
        File.WriteAllText(jsonPath, json);

        var parsedJson = JsonSerializer.Deserialize<Dictionary<string, JsonElement>>(File.ReadAllText(jsonPath));
        Console.WriteLine("JSON parsed keys: " + string.Join(", ", parsedJson!.Keys));

        // CSV write/read (simple parser).
        File.WriteAllLines(csvPath, new[]
        {
            "id,name,score",
            "1,Alice,95",
            "2,Bob,88"
        });

        var lines = File.ReadAllLines(csvPath);
        var headers = lines[0].Split(',');
        var parsedCsv = new List<Dictionary<string, string>>();
        for (int i = 1; i < lines.Length; i++)
        {
            var parts = lines[i].Split(',');
            var row = new Dictionary<string, string>();
            for (int j = 0; j < headers.Length; j++)
            {
                row[headers[j]] = parts[j];
            }
            parsedCsv.Add(row);
        }
        Console.WriteLine("CSV parsed rows: " + parsedCsv.Count);

        // Path API examples.
        Console.WriteLine("Path exists: " + File.Exists(textPath));
        Console.WriteLine("Path fileName: " + Path.GetFileName(textPath));
        Console.WriteLine("Path directory: " + Path.GetDirectoryName(textPath));
    }
}
