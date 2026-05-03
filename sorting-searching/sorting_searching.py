from bisect import bisect_left


# --- Manual algorithms ---

def bubble_sort(arr: list[int]) -> list[int]:
    """O(n^2) comparison sort."""
    result = arr[:]
    n = len(result)
    for i in range(n):
        for j in range(0, n - i - 1):
            if result[j] > result[j + 1]:
                result[j], result[j + 1] = result[j + 1], result[j]
    return result


def merge_sort(arr: list[int]) -> list[int]:
    """O(n log n) divide-and-conquer sort."""
    if len(arr) <= 1:
        return arr[:]
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return _merge(left, right)


def _merge(left: list[int], right: list[int]) -> list[int]:
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result


def binary_search(arr: list[int], target: int) -> int:
    """Returns index of target in sorted arr, or -1 if not found."""
    lo, hi = 0, len(arr) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1
    return -1


def main() -> None:
    print("Language: Python")
    unsorted = [64, 34, 25, 12, 22, 11, 90]
    print("Original:         ", unsorted)

    # Manual sorts
    print("Bubble sort:      ", bubble_sort(unsorted))
    print("Merge sort:       ", merge_sort(unsorted))

    # Built-in sort (Timsort)
    built_in = sorted(unsorted)
    print("Built-in sorted() :", built_in)

    # Manual binary search
    sorted_arr = sorted(unsorted)
    idx = binary_search(sorted_arr, 25)
    print(f"Manual binary search for 25: index {idx}")

    # Built-in binary search (bisect)
    bi_idx = bisect_left(sorted_arr, 25)
    print(f"bisect_left for 25:          index {bi_idx}")

    # Built-in search in list
    print(f"list.index() for 25:         index {sorted_arr.index(25)}")


if __name__ == "__main__":
    main()
