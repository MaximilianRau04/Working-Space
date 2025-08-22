#include <iostream>
#include <string>
#include <cmath>    

namespace first {
    int x = 1;
}

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

    std::string cars[] = {"BMW", "Audi", "Mercedes"};

    cars[0] = "Porsche";
    std::cout << sizeof(cars[0])<< '\n';

    return 0;
}