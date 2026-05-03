import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class FileHandlingIo {

    static String toJson(Map<String, Object> payload) {
        // Minimal JSON serializer for demonstration without external libraries.
        @SuppressWarnings("unchecked")
        List<String> skills = (List<String>) payload.get("skills");
        StringBuilder sb = new StringBuilder();
        sb.append("{\n");
        sb.append("  \"name\": \"").append(payload.get("name")).append("\",\n");
        sb.append("  \"skills\": [");
        for (int i = 0; i < skills.size(); i++) {
            sb.append("\"").append(skills.get(i)).append("\"");
            if (i + 1 < skills.size()) sb.append(", ");
        }
        sb.append("],\n");
        sb.append("  \"active\": ").append(payload.get("active")).append("\n");
        sb.append("}\n");
        return sb.toString();
    }

    static Map<String, String> parseSimpleJson(String json) {
        // Tiny parser for this known structure; keeps example dependency-free.
        Map<String, String> result = new HashMap<>();
        for (String line : json.split("\\n")) {
            String trimmed = line.trim();
            if (trimmed.startsWith("\"name\"")) {
                result.put("name", trimmed.split(":")[1].replace("\"", "").replace(",", "").trim());
            }
            if (trimmed.startsWith("\"active\"")) {
                result.put("active", trimmed.split(":")[1].replace(",", "").trim());
            }
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        System.out.println("Language: Java");

        Path baseDir = Paths.get(System.getProperty("user.dir"));
        Path dataDir = baseDir.resolve("data");
        Files.createDirectories(dataDir);

        Path textPath = dataDir.resolve("sample.txt");
        Path jsonPath = dataDir.resolve("sample.json");
        Path csvPath = dataDir.resolve("sample.csv");

        // Buffered text write/read.
        try (BufferedWriter writer = Files.newBufferedWriter(textPath, StandardCharsets.UTF_8)) {
            writer.write("line-1\n");
            writer.write("line-2\n");
        }

        try (BufferedReader reader = Files.newBufferedReader(textPath, StandardCharsets.UTF_8)) {
            System.out.println("Text read:");
            reader.lines().forEach(System.out::println);
        }

        // JSON write/read (manual minimal parser/serializer).
        Map<String, Object> payload = new HashMap<>();
        payload.put("name", "Nazmul");
        payload.put("skills", List.of("python", "javascript", "java", "csharp", "cpp"));
        payload.put("active", true);

        Files.writeString(jsonPath, toJson(payload), StandardCharsets.UTF_8);
        String jsonContent = Files.readString(jsonPath, StandardCharsets.UTF_8);
        Map<String, String> parsedJson = parseSimpleJson(jsonContent);
        System.out.println("JSON parsed (partial): " + parsedJson);

        // CSV write/read (simple parser).
        List<String> csvLines = List.of(
            "id,name,score",
            "1,Alice,95",
            "2,Bob,88"
        );
        Files.write(csvPath, csvLines, StandardCharsets.UTF_8);

        List<String> readLines = Files.readAllLines(csvPath, StandardCharsets.UTF_8);
        String[] headers = readLines.get(0).split(",");
        List<Map<String, String>> parsedCsv = new ArrayList<>();
        for (int i = 1; i < readLines.size(); i++) {
            String[] parts = readLines.get(i).split(",");
            Map<String, String> row = new HashMap<>();
            for (int j = 0; j < headers.length; j++) {
                row.put(headers[j], parts[j]);
            }
            parsedCsv.add(row);
        }
        System.out.println("CSV parsed: " + parsedCsv);

        // Path API examples.
        System.out.println("Path exists: " + Files.exists(textPath));
        System.out.println("Path fileName: " + textPath.getFileName());
        System.out.println("Path parent: " + textPath.getParent());
    }
}
