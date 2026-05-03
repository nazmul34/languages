using System;
using System.Collections.Generic;

// Interface
interface IAnimal
{
    string Speak();
    string Describe();
}

// Abstract class
abstract class Animal : IAnimal
{
    protected string name;

    public Animal(string name)
    {
        this.name = name;
    }

    public abstract string Speak();

    public virtual string Describe()
    {
        return $"I am {name}";
    }
}

// Concrete class: Dog
class Dog : Animal
{
    public Dog(string name) : base(name) { }

    public override string Speak()
    {
        return $"{name} says: Woof!";
    }
}

// Concrete class: Cat
class Cat : Animal
{
    public Cat(string name) : base(name) { }

    public override string Speak()
    {
        return $"{name} says: Meow!";
    }
}

class ObjectOrientedProgramming
{
    static void Main()
    {
        Console.WriteLine("Language: C#");

        List<IAnimal> animals = new List<IAnimal>
        {
            new Dog("Rex"),
            new Cat("Whiskers")
        };

        foreach (var animal in animals)
        {
            Console.WriteLine(animal.Speak());
            Console.WriteLine(animal.Describe());
        }
    }
}
