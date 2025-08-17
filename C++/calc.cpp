#include <iostream>
#include <cmath>

double divide(double x, double y);
double mySqrt(double x);
double power(double base, int exponent);
int mod(int x, int y);
int factorial(int n);

int main() {

    double a;
    double b;
    char sign;
    std::cout << "Enter a number: ";
    std::cin >> a;
    std::cout << "Enter an operator (+, -, *, /, %, ^, !, s (sqrt)): ";
    std::cin >> sign;

    if (sign == '!') {
        std::cout << "Result: " << factorial((int)a) << '\n';
    } else if (sign == 's') {
        std::cout << "Result: " << mySqrt(a) << '\n';
    } else {
        std::cout << "Enter another number: ";
        std::cin >> b;

        switch (sign) {
        case '+':
            std::cout << "Result: " << a + b << '\n';
            break;
        case '-':
            std::cout << "Result: " << a - b << '\n';
            break;
        case '*':
            std::cout << "Result: " << a * b << '\n';
            break;
        case '/':
            std::cout << "Result: " << divide(a, b) << '\n';
            break;
        case '%':
            std::cout << "Result: " << mod((int)a, (int)b) << '\n';
            break;
        case '^':
            std::cout << "Result: " << power(a, b) << '\n';
            break;
        default:
            std::cout << "Error: Invalid operator." << '\n';
            break;
        }
    }

    return 0;
}

double divide(double x, double y) {
    if (y == 0) {
        std::cerr << "Error: Division by zero is not allowed." << std::endl;
        return 0;
    }
    return x / y;
}

double mySqrt(double x) {
    if (x < 0) {
        std::cerr << "Error: Square root of negative number is not allowed." << std::endl;
        return -1;
    }
    return std::sqrt(x);
}

double power(double base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent < 0) return 1 / power(base, -exponent);

    return base * power(base, exponent - 1);
}

int mod(int x, int y) {
    if (y == 0) {
        std::cerr << "Error: Division by zero is not allowed." << std::endl;
        return -1;
    }
    return x % y;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}
