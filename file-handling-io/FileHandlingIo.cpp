#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

std::map<std::string, std::string> parseSimpleJson(const std::string& content) {
    // Minimal parser for known fields in this demo.
    std::map<std::string, std::string> out;
    if (auto pos = content.find("\"name\""); pos != std::string::npos) {
        auto start = content.find('"', pos + 6);
        start = content.find('"', start + 1);
        auto end = content.find('"', start + 1);
        out["name"] = content.substr(start + 1, end - start - 1);
    }
    out["active"] = content.find("\"active\": true") != std::string::npos ? "true" : "false";
    return out;
}

int main() {
    std::cout << "Language: C++\n";

    fs::path baseDir = fs::current_path();
    fs::path dataDir = baseDir / "data";
    fs::create_directories(dataDir);

    fs::path textPath = dataDir / "sample.txt";
    fs::path jsonPath = dataDir / "sample.json";
    fs::path csvPath = dataDir / "sample.csv";

    // Buffered text write/read via fstream buffers.
    {
        std::ofstream out(textPath, std::ios::out | std::ios::trunc);
        out << "line-1\n";
        out << "line-2\n";
    }

    {
        std::ifstream in(textPath);
        std::cout << "Text read:\n";
        std::string line;
        while (std::getline(in, line)) {
            std::cout << line << "\n";
        }
    }

    // JSON write/read (manual parsing for demo without external libs).
    {
        std::ofstream out(jsonPath, std::ios::out | std::ios::trunc);
        out << "{\n";
        out << "  \"name\": \"Nazmul\",\n";
        out << "  \"skills\": [\"python\", \"javascript\", \"java\", \"csharp\", \"cpp\"],\n";
        out << "  \"active\": true\n";
        out << "}\n";
    }

    std::string jsonContent;
    {
        std::ifstream in(jsonPath);
        std::ostringstream ss;
        ss << in.rdbuf();
        jsonContent = ss.str();
    }
    auto parsedJson = parseSimpleJson(jsonContent);
    std::cout << "JSON parsed (partial): name=" << parsedJson["name"]
              << ", active=" << parsedJson["active"] << "\n";

    // CSV write/read.
    {
        std::ofstream out(csvPath, std::ios::out | std::ios::trunc);
        out << "id,name,score\n";
        out << "1,Alice,95\n";
        out << "2,Bob,88\n";
    }

    std::vector<std::map<std::string, std::string>> rows;
    {
        std::ifstream in(csvPath);
        std::string headerLine;
        std::getline(in, headerLine);

        std::vector<std::string> headers;
        std::stringstream hs(headerLine);
        std::string part;
        while (std::getline(hs, part, ',')) headers.push_back(part);

        std::string line;
        while (std::getline(in, line)) {
            std::stringstream ls(line);
            std::vector<std::string> values;
            while (std::getline(ls, part, ',')) values.push_back(part);

            std::map<std::string, std::string> row;
            for (size_t i = 0; i < headers.size() && i < values.size(); ++i) {
                row[headers[i]] = values[i];
            }
            rows.push_back(row);
        }
    }
    std::cout << "CSV parsed rows: " << rows.size() << "\n";

    // Path API examples.
    std::cout << "Path exists: " << (fs::exists(textPath) ? "true" : "false") << "\n";
    std::cout << "Path filename: " << textPath.filename().string() << "\n";
    std::cout << "Path parent: " << textPath.parent_path().string() << "\n";

    return 0;
}
