#include <iostream>
#include <memory>

class Animal {
public:
    virtual void speak() = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() override { std::cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
    void speak() override { std::cout << "Meow!\n"; }
};



class AnimalFactory {
public://At compile time, the function is associated with the class, not an instance.
    static std::unique_ptr<Animal> createAnimal(const std::string& type) {  //This tells the compiler that the function returns a smart pointer managing a polymorphic base class (Animal).
        if (type == "dog") return std::make_unique<Dog>();   // creates a Dog instance on the heap. 
        else if (type == "cat") return std::make_unique<Cat>();
        else return nullptr;
    }
};

#include <iostream>

int main() {
    /*
    createAnimal() is a factory function using smart pointers and polymorphism.
    At compile time:
        Vtables are set up for virtual dispatch.
        Templates like make_unique are instantiated.
        Type-safe conversions between unique_ptr<Dog> → unique_ptr<Animal> are enforced.
    At runtime:
    The correct speak() implementation is chosen via virtual function dispatch.
    */
    auto dog = AnimalFactory::createAnimal("dog");
    if (dog) dog->speak();  // Output: Woof!

    auto cat = AnimalFactory::createAnimal("cat");
    if (cat) cat->speak();  // Output: Meow!

    auto unknown = AnimalFactory::createAnimal("elephant");
    if (unknown) unknown->speak();
    else std::cout << "Unknown animal type\n";

    return 0;
}

/*
 Why Factory Pattern Is Needed

    Decouples object creation from the client code.
    Avoids new scattered throughout the codebase.
    Allows flexible addition of new types (e.g., adding Bird) without touching client code.

Benefits:
    Single Responsibility: Object creation is centralized.

    Open/Closed Principle: Can extend behavior (add new animal types) without modifying existing logic.

    Polymorphism: Client uses base class pointers without knowing concrete types.
*/