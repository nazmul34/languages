#include <algorithm>
#include <iostream>
#include <vector>

// --- Manual algorithms ---

std::vector<int> bubbleSort(std::vector<int> arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> result;
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) result.push_back(left[i++]);
        else result.push_back(right[j++]);
    }
    while (i < left.size()) result.push_back(left[i++]);
    while (j < right.size()) result.push_back(right[j++]);
    return result;
}

std::vector<int> mergeSort(std::vector<int> arr) {
    if (arr.size() <= 1) return arr;
    size_t mid = arr.size() / 2;
    auto left = mergeSort({arr.begin(), arr.begin() + mid});
    auto right = mergeSort({arr.begin() + mid, arr.end()});
    return merge(left, right);
}

int binarySearch(const std::vector<int>& arr, int target) {
    int lo = 0, hi = static_cast<int>(arr.size()) - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

void print(const std::string& label, const std::vector<int>& arr) {
    std::cout << label << " [";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? ", " : "");
    }
    std::cout << "]\n";
}

int main() {
    std::cout << "Language: C++\n";
    std::vector<int> unsorted = {64, 34, 25, 12, 22, 11, 90};
    print("Original:        ", unsorted);

    // Manual sorts
    print("Bubble sort:     ", bubbleSort(unsorted));
    print("Merge sort:      ", mergeSort(unsorted));

    // Built-in sort (introsort)
    std::vector<int> builtIn = unsorted;
    std::sort(builtIn.begin(), builtIn.end());
    print("std::sort():     ", builtIn);

    // Manual binary search
    std::vector<int> sorted = mergeSort(unsorted);
    std::cout << "Manual binary search for 25: index " << binarySearch(sorted, 25) << "\n";

    // Built-in binary search (lower_bound)
    auto it = std::lower_bound(sorted.begin(), sorted.end(), 25);
    int idx = static_cast<int>(it - sorted.begin());
    std::cout << "std::lower_bound for 25:     index " << idx << "\n";

    // std::binary_search (returns bool, not index)
    bool found = std::binary_search(sorted.begin(), sorted.end(), 25);
    std::cout << "std::binary_search found 25: " << (found ? "true" : "false") << "\n";

    return 0;
}
