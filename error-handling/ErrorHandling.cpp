#include <exception>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

class InvalidAgeException : public std::runtime_error {
public:
    explicit InvalidAgeException(const std::string& message) : std::runtime_error(message) {}
};

class ConfigException : public std::runtime_error {
public:
    explicit ConfigException(const std::string& message) : std::runtime_error(message) {}
};

int parseAge(const std::string& text) {
    try {
        size_t idx = 0;
        int age = std::stoi(text, &idx);
        if (idx != text.size()) {
            throw InvalidAgeException("Age must be a number: " + text);
        }
        if (age < 0) {
            throw InvalidAgeException("Age cannot be negative");
        }
        return age;
    } catch (const std::invalid_argument&) {
        throw InvalidAgeException("Age must be a number: " + text);
    } catch (const std::out_of_range&) {
        throw InvalidAgeException("Age value is out of range");
    }
}

std::string loadConfig(const std::map<std::string, std::string>& data) {
    auto it = data.find("mode");
    if (it == data.end()) {
        throw ConfigException("Missing 'mode' in config");
    }
    return it->second;
}

void checkedVsUncheckedNote() {
    std::cout << "C++ note: no checked exceptions; all throws are runtime.\n";
}

int main() {
    std::cout << "Language: C++\n";

    try {
        std::cout << "Parsed age: " << parseAge("21") << "\n";
        std::cout << "Parsed age: " << parseAge("oops") << "\n";
    } catch (const InvalidAgeException& ex) {
        std::cout << "Caught custom exception: " << ex.what() << "\n";
    }

    std::cout << "Finally equivalent: use scope-based cleanup (RAII) in C++\n";

    try {
        std::string mode = loadConfig({});
        std::cout << "Mode: " << mode << "\n";
    } catch (const ConfigException& ex) {
        std::cout << "Caught runtime-style custom exception: " << ex.what() << "\n";
    }

    checkedVsUncheckedNote();
    return 0;
}
