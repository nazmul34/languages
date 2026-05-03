#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Abstract base class
class Animal {
public:
    virtual ~Animal() = default;

    virtual std::string speak() const = 0;

    virtual std::string describe() const {
        return "I am " + name;
    }

protected:
    std::string name;

    Animal(const std::string& n) : name(n) {}
};

// Concrete class: Dog
class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {}

    std::string speak() const override {
        return name + " says: Woof!";
    }
};

// Concrete class: Cat
class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal(name) {}

    std::string speak() const override {
        return name + " says: Meow!";
    }
};

int main() {
    std::cout << "Language: C++\n";

    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>("Rex"));
    animals.push_back(std::make_unique<Cat>("Whiskers"));

    for (const auto& animal : animals) {
        std::cout << animal->speak() << "\n";
        std::cout << animal->describe() << "\n";
    }

    return 0;
}
