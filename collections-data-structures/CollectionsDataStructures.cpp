#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

int main() {
    std::cout << "Language: C++\n";

    // Array
    std::array<int, 3> numbersArray = {10, 20, 30};
    std::cout << "Array: [" << numbersArray[0] << ", " << numbersArray[1] << ", " << numbersArray[2] << "]\n";

    // List-like dynamic array
    std::vector<int> numbersList = {1, 2, 3};
    numbersList.push_back(4);
    std::cout << "Vector list: [";
    for (size_t i = 0; i < numbersList.size(); ++i) {
        std::cout << numbersList[i] << (i + 1 < numbersList.size() ? ", " : "");
    }
    std::cout << "]\n";

    // Map
    std::map<std::string, int> scores = {{"alice", 95}, {"bob", 88}};
    scores["carol"] = 91;
    std::cout << "Map:\n";
    for (const auto& pair : scores) {
        std::cout << "  " << pair.first << ": " << pair.second << "\n";
    }

    // Set
    std::set<int> uniqueValues = {1, 2, 2, 3};
    uniqueValues.insert(4);
    std::cout << "Set: [";
    for (auto it = uniqueValues.begin(); it != uniqueValues.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != uniqueValues.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    // Queue (FIFO)
    std::queue<std::string> queue;
    queue.push("first");
    queue.push("second");
    queue.push("third");
    std::string removedFromQueue = queue.front();
    queue.pop();
    std::cout << "Queue removed: " << removedFromQueue << " Remaining size: " << queue.size() << "\n";

    // Stack (LIFO)
    std::stack<std::string> stack;
    stack.push("bottom");
    stack.push("middle");
    stack.push("top");
    std::string removedFromStack = stack.top();
    stack.pop();
    std::cout << "Stack removed: " << removedFromStack << " Remaining size: " << stack.size() << "\n";

    return 0;
}
