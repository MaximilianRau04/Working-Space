#include <iostream>
#include <ctime>


int main() {

    int guess;
    int tries = 0;
    int num;

    srand(time(NULL)); 
    num = (rand() % 100) + 1;

    std::cout << "Welcome to the Guessing Game!" << '\n';

    do {
        std::cout << "Enter your guess (1-100): ";
        std::cin >> guess;
        tries++;
        if (guess > num) {
            std::cout << "Too high! Try again." << '\n';
        } else if (guess < num) {
            std::cout << "Too low! Try again." << '\n';
        } else if (guess == num) {
            std::cout << "Congratulations! You guessed the number in " << tries << " tries." << '\n';
        } else {
            std::cout << "Invalid input! Please enter a number between 1 and 100." << '\n';
            tries--;
        }

    } while (guess != num);

    return 0;
}