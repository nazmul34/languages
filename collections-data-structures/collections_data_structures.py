from collections import deque


def main() -> None:
    print("Language: Python")

    # Array-like structure (dynamic array in Python)
    numbers_array = [10, 20, 30]
    print("Array-like list:", numbers_array)

    # List operations
    numbers_list = [1, 2, 3]
    numbers_list.append(4)
    print("List:", numbers_list)

    # Dictionary (map)
    scores = {"alice": 95, "bob": 88}
    scores["carol"] = 91
    print("Dictionary:", scores)

    # Set
    unique_values = {1, 2, 2, 3}
    unique_values.add(4)
    print("Set:", unique_values)

    # Queue (FIFO)
    queue = deque(["first", "second"])
    queue.append("third")
    removed_from_queue = queue.popleft()
    print("Queue removed:", removed_from_queue, "Remaining:", list(queue))

    # Stack (LIFO)
    stack = ["bottom", "middle"]
    stack.append("top")
    removed_from_stack = stack.pop()
    print("Stack removed:", removed_from_stack, "Remaining:", stack)


if __name__ == "__main__":
    main()
