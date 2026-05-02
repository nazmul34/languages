#include <iostream>
#include <map>
#include <string>
#include <vector>

void mutate_list(std::vector<std::string>& items) {
    items.push_back("new-item");
}

int main() {
    int mutable_count = 1;
    const std::string immutable_name = "Nazmul";

    std::vector<std::string> items{"a", "b"};
    std::map<std::string, std::string> config{{"mode", "demo"}};

    std::string scope_value;
    {
        std::string inside_block = "inside";
        scope_value = inside_block;
    }

    mutate_list(items);
    config["mode"] = "updated";
    mutable_count = mutable_count + 1;

    std::cout << "Language: C++\n";
    std::cout << "immutable_name=" << immutable_name << "\n";
    std::cout << "mutable_count=" << mutable_count << "\n";
    std::cout << "scope_value=" << scope_value << "\n";

    std::cout << "items=[";
    for (std::size_t i = 0; i < items.size(); ++i) {
        std::cout << items[i] << (i + 1 < items.size() ? ", " : "");
    }
    std::cout << "]\n";

    std::cout << "config=mode:" << config["mode"] << "\n";
    return 0;
}
