#include <iostream>


int main() {

    std::string name;
    int age;

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Enter your name: ";
    std::cin.ignore();  // Clear the newline character from the input buffer
    std::getline(std::cin, name);

    std::cout << "Hello, " << name << "! You are " << age << " years old." << '\n';

    return 0;
}