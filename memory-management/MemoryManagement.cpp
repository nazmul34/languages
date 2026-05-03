#include <chrono>
#include <iostream>
#include <memory>
#include <vector>

class BigObject {
public:
    explicit BigObject(size_t size) : data(size, 0) {}
    std::vector<int> data;
};

void lifetimeDemo() {
    std::cout << "\n-- Object lifetime --\n";

    // Stack object: destroyed automatically at end of scope.
    {
        BigObject stackObj(100000);
        std::cout << "Stack object len(data)= " << stackObj.data.size() << "\n";
    }

    // Heap object with RAII smart pointer.
    {
        auto heapObj = std::make_unique<BigObject>(100000);
        std::cout << "Heap object len(data)= " << heapObj->data.size() << "\n";
    }

    std::cout << "Lifetime managed deterministically by scope/RAII\n";
}

void performanceTradeoff() {
    std::cout << "\n-- Performance tradeoff --\n";

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::unique_ptr<BigObject>> objs;
    objs.reserve(200000);
    for (int i = 0; i < 200000; ++i) {
        objs.push_back(std::make_unique<BigObject>(4));
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Allocated 200000 heap objects in " << ms << " ms\n";
    std::cout << "Tradeoff: manual/RAII control gives predictability and speed,";
    std::cout << " but incorrect ownership can cause bugs if misused\n";
}

int main() {
    std::cout << "Language: C++\n";
    lifetimeDemo();
    std::cout << "\n-- Garbage collection behavior --\n";
    std::cout << "C++ has no built-in GC; memory is managed explicitly or via RAII\n";
    performanceTradeoff();
    return 0;
}
