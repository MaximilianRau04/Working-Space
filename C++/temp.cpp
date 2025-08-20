#include <iostream> 
#include <cmath>

int main() {
    
    double temp;
    char unit;

    std::cout << "Enter unit to convert to (C/F): ";
    std::cin >> unit; 

    if (unit == 'F' || unit == 'f') {
        std::cout << "Enter temperature in Celsius: ";
        std::cin >> temp;
        double fahrenheit = std::floor(((temp * 9/5) + 32) * 10) / 10.0;
        std::cout << "Temperature in Fahrenheit: " << fahrenheit << "°F" << '\n';
    } else if (unit == 'C' || unit == 'c') {
        std::cout << "Enter temperature in Fahrenheit: ";
        std::cin >> temp;
        double celsius = std::floor(((temp - 32) * 5/9) * 10) / 10.0;
        std::cout << "Temperature in Celsius: " << celsius << "°C" << '\n';
    } else {
        std::cout << "Invalid unit. Please enter C or F." << '\n';
    }

    return 0;
}