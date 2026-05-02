def describe_types() -> None:
    age: int = 28
    temperature: float = 36.7
    name: str = "Nazmul"
    is_active: bool = True
    tags: list[str] = ["python", "types", "demo"]
    scores: dict[str, int] = {"math": 90, "science": 88}
    middle_name: str | None = None

    converted_age: str = str(age)
    parsed_number: int = int("42")

    print("Language: Python")
    print(f"age={age} ({type(age).__name__})")
    print(f"temperature={temperature} ({type(temperature).__name__})")
    print(f"name={name} ({type(name).__name__})")
    print(f"is_active={is_active} ({type(is_active).__name__})")
    print(f"tags={tags} ({type(tags).__name__})")
    print(f"scores={scores} ({type(scores).__name__})")
    print(f"middle_name={middle_name} ({type(middle_name).__name__})")
    print(f"converted_age={converted_age} ({type(converted_age).__name__})")
    print(f"parsed_number={parsed_number} ({type(parsed_number).__name__})")


if __name__ == "__main__":
    describe_types()
