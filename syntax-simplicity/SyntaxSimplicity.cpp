#include <iostream>
#include <vector>

bool isEven(int n) {
    return n % 2 == 0;
}

int main() {
    std::vector<int> numbers{5, 1, 4, 2, 3};
    std::vector<int> evenSquares;

    for (int n : numbers) {
        if (isEven(n)) {
            evenSquares.push_back(n * n);
        }
    }

    int total = 0;
    for (int value : evenSquares) {
        total += value;
    }

    std::cout << "Language: C++" << '\n';
    std::cout << "Input: [";
    for (std::size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << (i + 1 < numbers.size() ? ", " : "");
    }
    std::cout << "]\n";

    std::cout << "Even squares: [";
    for (std::size_t i = 0; i < evenSquares.size(); ++i) {
        std::cout << evenSquares[i] << (i + 1 < evenSquares.size() ? ", " : "");
    }
    std::cout << "]\n";

    std::cout << "Total: " << total << '\n';
    return 0;
}
