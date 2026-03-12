#include <iostream>
  

int getDigit(const int number);
int sumOddNumbers(const std::string cardNumber);
int sumEvenNumbers(const std::string cardNumber);

int main() {

    std::string cardNumber;
    int result = 0;

    std::cout << "Enter credit card number: ";
    std::cin >> cardNumber;

    result = sumEvenNumbers(cardNumber) + sumOddNumbers(cardNumber);

    if (result % 10 == 0) {
        std::cout << "Valid credit card number." << '\n';
    } else {
        std::cout << "Invalid credit card number." << '\n';
    }

    return 0;
}

int getDigit(const int number) {
    
    return number % 10 + (number / 10 % 10);
}
 
int sumOddNumbers(const std::string cardNumber) {
    int sum = 0;

    for (int i = cardNumber.length() - 1; i >= 0; i-=2) {
        sum += cardNumber[i] - '0';
    }
    return sum;
}

int sumEvenNumbers(const std::string cardNumber) {
    
    int sum = 0;

    for (int i = cardNumber.length() - 2; i >= 0; i-=2) {
        sum += getDigit((cardNumber[i] - '0') * 2);
    }
    return sum;
}