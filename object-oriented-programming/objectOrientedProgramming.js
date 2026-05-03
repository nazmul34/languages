// Base class
class Animal {
  constructor(name) {
    this.name = name;
  }

  // Method to be overridden
  speak() {
    throw new Error("speak() must be implemented in subclass");
  }

  describe() {
    return `I am ${this.name}`;
  }
}

// Inheritance: Dog extends Animal
class Dog extends Animal {
  speak() {
    return `${this.name} says: Woof!`;
  }
}

// Inheritance: Cat extends Animal
class Cat extends Animal {
  speak() {
    return `${this.name} says: Meow!`;
  }
}

function main() {
  console.log("Language: JavaScript");

  const animals = [new Dog("Rex"), new Cat("Whiskers")];

  animals.forEach((animal) => {
    console.log(animal.speak());
    console.log(animal.describe());
  });
}

main();
