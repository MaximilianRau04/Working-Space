#include <iostream>

class Human {
    public:
        std::string name;
        std::string occupation;
        int age;

        void eat() {
            std::cout << name << " is eating." << '\n';
        }

        void drink() {
            std::cout << name << " is drinking." << '\n';
        }

        void sleep() {
            std::cout << name << " is sleeping." << '\n';
        }
};

class Animal {
    public:
        bool alive = true;
        int age;

        void eat() {
            std::cout << (alive ? "The animal is eating." : "The animal is not alive.") << '\n';
        }

        void sleep() {
            std::cout << (alive ? "The animal is sleeping." : "The animal is not alive.") << '\n';
        }

    // Constructor
    Animal(bool alive, int age) {
        this->alive = alive;
        this->age = age;
    }

    Animal(int age) {
        this->age = age;
    }
};

class Dog : public Animal {
    public:
        std::string breed;

        Dog(std::string breed, int age) : Animal(age) {
            this->breed = breed;
        }

        void bark() {
            std::cout << "Woof! Woof!" << '\n';
        }
};

class Cat : public Animal {
    public:
        std::string color;

        Cat(std::string color, int age) : Animal(age) {
            this->color = color;
        }

        void meow() {
            std::cout << "Meow! Meow!" << '\n';
        }
};

class Stove {
    private:
        int temperature = 0;

    public:

        Stove(int temp) {
            setTemperature(temp);
        }

        void setTemperature(int temp) {
            if (temp < 0) {
                temperature = 0;
            } else if (temp >= 10) {
                temperature = 10;
            } else {
                this->temperature = temp;
            }
        }

        int getTemperature() {
            return temperature;
        }
};


int main() {
    Human person1;
    Human person2;
    Animal animal1("Lion", 5);
    Animal animal2("Elephant", 10);
    Dog dog1("Labrador", 3);

    person1.name = "John";
    person1.occupation = "Engineer";
    person1.age = 30;

    person2.name = "Jane";
    person2.occupation = "Doctor";
    person2.age = 28;

    person1.eat();
    person1.drink();
    person1.sleep();

    person2.eat();
    person2.drink();
    person2.sleep();

    animal1.eat();
    animal1.sleep();

    animal2.eat();
    animal2.sleep();

    return 0;
}