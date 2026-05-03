#include <chrono>
#include <future>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

// --- Threads ---

void workerThread(const std::string& name) {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Thread '" << name << "' done\n";
}

void runThreads() {
    std::cout << "\n-- Threads --\n";
    std::thread t1(workerThread, "A");
    std::thread t2(workerThread, "B");
    t1.join();  // wait for t1 to finish
    t2.join();  // wait for t2 to finish
}

// --- std::async / std::future (async/await equivalent) ---

std::string fetchData(const std::string& name, int delayMs) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    return "Data from '" + name + "'";
}

void runAsync() {
    std::cout << "\n-- std::async + std::future --\n";

    // Launch async tasks (may run on thread pool)
    std::future<std::string> fa = std::async(std::launch::async, fetchData, "source-A", 200);
    std::future<std::string> fb = std::async(std::launch::async, fetchData, "source-B", 100);
    std::future<std::string> fc = std::async(std::launch::async, fetchData, "source-C", 50);

    // .get() blocks until result is ready — like await
    std::cout << fa.get() << "\n";
    std::cout << fb.get() << "\n";
    std::cout << fc.get() << "\n";
}

// --- Parallel CPU work with multiple threads ---

void runParallel() {
    std::cout << "\n-- Parallel CPU work --\n";
    const int numThreads = 4;
    std::vector<std::thread> threads;
    std::vector<long long> results(numThreads, 0);

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back([i, &results]() {
            long long sum = 0;
            for (int j = i * 250000; j < (i + 1) * 250000; ++j) sum += j;
            results[i] = sum;
        });
    }
    for (auto& t : threads) t.join();

    long long total = 0;
    for (auto r : results) total += r;
    std::cout << "Parallel sum (0..999999): " << total << "\n";
}

int main() {
    std::cout << "Language: C++\n";
    runThreads();
    runAsync();
    runParallel();
    return 0;
}
