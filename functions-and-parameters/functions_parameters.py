def greet(name: str, prefix: str = "Hello") -> str:
    return f"{prefix}, {name}!"


def add(a: int, b: int = 0) -> int:
    return a + b


def apply_operation(a: int, b: int, operation):
    return operation(a, b)


def main() -> None:
    # Default parameter
    print(greet("Nazmul"))

    # Named parameter
    print(greet(name="Nazmul", prefix="Hi"))

    # Python has no classic overloading; defaults often replace it
    print(add(10))
    print(add(10, 5))

    # First-class function: a function can be stored in a variable and passed to another function.
    multiply = lambda x, y: x * y
    print(apply_operation(4, 3, multiply))


if __name__ == "__main__":
    main()
