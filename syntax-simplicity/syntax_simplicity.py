def is_even(n):
    return n % 2 == 0


def main():
    numbers = [5, 1, 4, 2, 3]
    even_squares = []

    for n in numbers:
        if is_even(n):
            even_squares.append(n * n)

    total = sum(even_squares)

    print("Language: Python")
    print(f"Input: {numbers}")
    print(f"Even squares: {even_squares}")
    print(f"Total: {total}")


if __name__ == "__main__":
    main()
