from abc import ABC, abstractmethod


class Animal(ABC):
    """Abstract base class demonstrating abstraction."""
    
    def __init__(self, name: str):
        self.name = name
    
    @abstractmethod
    def speak(self) -> str:
        pass
    
    def describe(self) -> str:
        return f"I am {self.name}"


class Dog(Animal):
    """Concrete class inheriting from abstract base."""
    
    def speak(self) -> str:
        return f"{self.name} says: Woof!"


class Cat(Animal):
    """Another concrete class with method override."""
    
    def speak(self) -> str:
        return f"{self.name} says: Meow!"


def main() -> None:
    print("Language: Python")
    
    animals: list[Animal] = [Dog("Rex"), Cat("Whiskers")]
    
    for animal in animals:
        print(animal.speak())
        print(animal.describe())


if __name__ == "__main__":
    main()
