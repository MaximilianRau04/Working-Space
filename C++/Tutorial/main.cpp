#include <iostream>
#include <string>
#include <cmath>    

namespace first {
    int x = 1;
}

template <typename T, typename U>

auto max (T x, U y) {
    return (x > y) ? x : y;
}

struct Car {
    std::string brand;
    std::string model;
    int year;
};

enum Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };


// typedef std::vector<std::pair<std::string, int>> pairList_t;
using text_t = std::string;
using number_t = int;

int main() {
    std::cout << "Hello, World!" << '\n';

    std::string name = "Maxi";
    std::cout << "Hello, " << name << "!" << '\n';

    int x = 3.14;
    char y = 100;

    std::cout << "x = " << x << '\n';
    std::cout << "y = " << static_cast<int>(y) << '\n';

    text_t firstName = "Maxi"; 
    number_t age = 25;
    // pairList_t pairList;

    double a; 
    double b;
    double c;

    //std::cout << "Enter the length of side a: ";
    //std::cin >> a;

    //std::cout << "Enter the length of side b: ";
    //std::cin >> b;

    //c = sqrt(pow(a, 2) + pow(b, 2));

    //std::cout << "The length of the hypotenuse is: " << c << '\n';

    int grade = 50;

    grade >= 60 ? std::cout << "Passed" << '\n' : std::cout << "Failed" << '\n';

    std::string cars[3] = {"BMW", "Audi", "Mercedes"};

    cars[0] = "Porsche";
    fill(cars+1, cars + sizeof(cars) / sizeof(cars[0]), "Unknown");

    std::cout << sizeof(cars[0])<< '\n';

    for (std::string car : cars) {
        std::cout << car << '\n';
    }

    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int index = -1;
    int myNum;

    /** 
    std::cout << "Enter an element to search for: ";
    std::cin >> myNum;

    for (int i = 0; i < size; i++) {
        if (numbers[i] == myNum) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        std::cout << "Element found at index: " << index << '\n';
    } else {
        std::cout << "Element not found." << '\n';
    }
    */

    std::string foods[5];
    int size1 = sizeof(foods) / sizeof(foods[0]);
    std::string temp;

    /** 
    for (int i = 0; i < size1; i++) {
        std::cout << "Enter food item or 'q' to quit " << ": ";
        std::getline(std::cin, temp);
        if (temp == "q") {
            break;
        } else {
            foods[i] = temp;
        }
    }

    std::cout << "You entered:" << '\n';
    for (int i = 0; !foods[i].empty(); i++) {
        std::cout << foods[i] << '\n';
    }
    */

    int *ptr = nullptr;
    int var = 42;
    ptr = &var;

    std::cout << max(1, '2') << '\n';

    Car car1;
    car1.brand = "Ford";
    car1.model = "Mustang";
    car1.year = 2020;

    std::cout << car1.brand << " " << car1.model << " " << car1.year << '\n';

    return 0;
}