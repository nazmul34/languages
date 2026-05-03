class AgeError(Exception):
    """Custom exception for invalid age values."""


class ConfigError(RuntimeError):
    """Custom unchecked-style exception (runtime error category)."""


def parse_age(text: str) -> int:
    try:
        age = int(text)
    except ValueError as exc:
        raise AgeError(f"Age must be a number: {text}") from exc

    if age < 0:
        raise AgeError("Age cannot be negative")

    return age


def load_config(data: dict) -> str:
    if "mode" not in data:
        raise ConfigError("Missing 'mode' in config")
    return data["mode"]


def checked_vs_unchecked_note() -> None:
    print("Python note: all exceptions are runtime; no checked exception enforcement.")


def main() -> None:
    print("Language: Python")

    # try/except/finally
    try:
        print("Parsed age:", parse_age("21"))
        print("Parsed age:", parse_age("oops"))
    except AgeError as err:
        print("Caught custom exception:", err)
    finally:
        print("Finally block: cleanup/logging runs always")

    # Another custom exception example
    try:
        mode = load_config({})
        print("Mode:", mode)
    except ConfigError as err:
        print("Caught runtime-style custom exception:", err)

    checked_vs_unchecked_note()


if __name__ == "__main__":
    main()
