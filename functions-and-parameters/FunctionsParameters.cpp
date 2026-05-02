#include <functional>
#include <iostream>
#include <string>

std::string greet(const std::string& name, const std::string& prefix = "Hello") {
    return prefix + ", " + name + "!";
}

// Overloading example
int add(int a) {
    return add(a, 0);
}

int add(int a, int b) {
    return a + b;
}

int apply_operation(int a, int b, const std::function<int(int, int)>& operation) {
    return operation(a, b);
}

int main() {
    std::cout << greet("Nazmul") << "\n";

    // C++ has no named parameters; pass by position.
    std::cout << greet("Nazmul", "Hi") << "\n";

    std::cout << add(10) << "\n";
    std::cout << add(10, 5) << "\n";

    // First-class function: a lambda can be stored in a variable and passed to another function.
    auto multiply = [](int x, int y) { return x * y; };
    std::cout << apply_operation(4, 3, multiply) << "\n";

    return 0;
}
