// Interface
interface IAnimal {
    String speak();
    String describe();
}

// Abstract class
abstract class Animal implements IAnimal {
    protected String name;

    public Animal(String name) {
        this.name = name;
    }

    @Override
    abstract public String speak();

    @Override
    public String describe() {
        return "I am " + name;
    }
}

// Concrete class: Dog
class Dog extends Animal {
    public Dog(String name) {
        super(name);
    }

    @Override
    public String speak() {
        return name + " says: Woof!";
    }
}

// Concrete class: Cat
class Cat extends Animal {
    public Cat(String name) {
        super(name);
    }

    @Override
    public String speak() {
        return name + " says: Meow!";
    }
}

public class ObjectOrientedProgramming {
    public static void main(String[] args) {
        System.out.println("Language: Java");

        IAnimal[] animals = {new Dog("Rex"), new Cat("Whiskers")};

        for (IAnimal animal : animals) {
            System.out.println(animal.speak());
            System.out.println(animal.describe());
        }
    }
}
