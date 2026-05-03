from functools import reduce
from typing import Callable


def main() -> None:
    print("Language: Python")

    numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    # --- Lambdas ---
    double: Callable[[int], int] = lambda x: x * 2
    is_even: Callable[[int], bool] = lambda x: x % 2 == 0
    add: Callable[[int, int], int] = lambda a, b: a + b
    print("Lambda double(5):   ", double(5))

    # --- map ---
    doubled = list(map(double, numbers))
    print("map (double):       ", doubled)

    # --- filter ---
    evens = list(filter(is_even, numbers))
    print("filter (evens):     ", evens)

    # --- reduce ---
    total = reduce(add, numbers)
    print("reduce (sum):       ", total)

    # --- Composed pipeline ---
    result = reduce(add, map(double, filter(is_even, numbers)))
    print("filter→map→reduce: ", result)  # even numbers, doubled, summed

    # --- Immutability patterns ---
    # Tuples are immutable; list operations return new lists, originals unchanged
    original = (1, 2, 3)
    extended = original + (4, 5)           # new tuple — original unchanged
    print("Immutable tuple original:  ", original)
    print("Immutable tuple extended:  ", extended)

    # list comprehension returns new list
    squared = [x ** 2 for x in numbers]
    print("List comprehension (new):  ", squared)
    print("Original unchanged:        ", numbers)


if __name__ == "__main__":
    main()
