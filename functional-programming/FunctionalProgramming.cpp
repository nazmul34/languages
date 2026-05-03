#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::cout << "Language: C++\n";

    const std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // --- Lambdas ---
    auto doubleIt = [](int x) { return x * 2; };
    auto isEven   = [](int x) { return x % 2 == 0; };
    auto add      = [](int a, int b) { return a + b; };
    std::cout << "Lambda double(5):   " << doubleIt(5) << "\n";

    // --- map (std::transform) ---
    std::vector<int> doubled(numbers.size());
    std::transform(numbers.begin(), numbers.end(), doubled.begin(), doubleIt);
    std::cout << "transform/map:      [";
    for (size_t i = 0; i < doubled.size(); ++i)
        std::cout << doubled[i] << (i + 1 < doubled.size() ? ", " : "");
    std::cout << "]\n";

    // --- filter (std::copy_if) ---
    std::vector<int> evens;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evens), isEven);
    std::cout << "copy_if/filter:     [";
    for (size_t i = 0; i < evens.size(); ++i)
        std::cout << evens[i] << (i + 1 < evens.size() ? ", " : "");
    std::cout << "]\n";

    // --- reduce (std::accumulate) ---
    int total = std::accumulate(numbers.begin(), numbers.end(), 0, add);
    std::cout << "accumulate/reduce:  " << total << "\n";

    // --- Composed pipeline: filter → map → reduce ---
    std::vector<int> evenDoubled;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(evenDoubled), isEven);
    std::transform(evenDoubled.begin(), evenDoubled.end(), evenDoubled.begin(), doubleIt);
    int result = std::accumulate(evenDoubled.begin(), evenDoubled.end(), 0, add);
    std::cout << "filter→map→reduce: " << result << "\n";

    // --- Immutability patterns ---
    // const vector — cannot be modified after construction
    const std::vector<int> original = {1, 2, 3};
    // original.push_back(4) would be a compile error
    std::vector<int> extended = original; // copy — original unchanged
    extended.push_back(4);
    std::cout << "Const original:     [" << original[0] << ", " << original[1] << ", " << original[2] << "]\n";
    std::cout << "Extended (copy):    [";
    for (size_t i = 0; i < extended.size(); ++i)
        std::cout << extended[i] << (i + 1 < extended.size() ? ", " : "");
    std::cout << "]\n";

    std::cout << "Original numbers unchanged: size=" << numbers.size() << "\n";
    return 0;
}
