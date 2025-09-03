#include <iostream>
#include <string>
#include <cmath>    


int main() {
    std::string questions[] = {"1. What year was C++ created?",
                                "2. Who is known as the father of C++?",
                                "3. What is the latest version of C++?"};

    std::string options[][4] = {{"A. 1979", "B. 1985", "C. 1991"},
                                {"A. Bjarne Stroustrup", "B. James Gosling", "C. Dennis Ritchie"},
                                {"A. C++11", "B. C++14", "C. C++17"}};

    char answers[] = {'B', 'A', 'C'};

    int size = sizeof(questions) / sizeof(questions[0]);
    int correctAnswers = 0;

    for (int i = 0; i < size; i++) {
        std::cout << questions[i] << '\n';
        for (const auto& option : options[i]) {
            std::cout << option << '\n';
        }
        char userAnswer;
        std::cout << "Your answer: ";
        std::cin >> userAnswer;
        if (userAnswer == answers[i]) {
            std::cout << "Correct!\n";
            correctAnswers++;
        } else {
            std::cout << "Wrong! The correct answer is " << answers[i] << ".\n";
        }
    }
    std::cout << "You got " << correctAnswers << " out of " << size << " correct!" << '\n';

    return 0;
}