#include <iostream>
#include <map>
#include <optional>
#include <string>
#include <vector>

int main() {
    int age = 28;
    double temperature = 36.7;
    std::string name = "Nazmul";
    bool is_active = true;
    std::vector<std::string> tags{"cpp", "types", "demo"};
    std::map<std::string, int> scores{{"math", 90}, {"science", 88}};
    std::optional<std::string> middle_name = std::nullopt;

    std::string converted_age = std::to_string(age);
    int parsed_number = std::stoi("42");

    std::cout << "Language: C++\n";
    std::cout << "age=" << age << " (int)\n";
    std::cout << "temperature=" << temperature << " (double)\n";
    std::cout << "name=" << name << " (std::string)\n";
    std::cout << "is_active=" << is_active << " (bool)\n";

    std::cout << "tags=[";
    for (std::size_t i = 0; i < tags.size(); ++i) {
        std::cout << tags[i] << (i + 1 < tags.size() ? ", " : "");
    }
    std::cout << "] (std::vector<std::string>)\n";

    std::cout << "scores=math:" << scores["math"] << ", science:" << scores["science"]
              << " (std::map<std::string, int>)\n";
    std::cout << "middle_name=" << (middle_name.has_value() ? middle_name.value() : "null")
              << " (std::optional<std::string>)\n";
    std::cout << "converted_age=" << converted_age << " (std::string)\n";
    std::cout << "parsed_number=" << parsed_number << " (int)\n";

    return 0;
}
