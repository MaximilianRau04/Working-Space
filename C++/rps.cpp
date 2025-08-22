#include <iostream>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main() {

    char player;
    char computer;

    player = getUserChoice();
    std::cout << "You chose: ";
    showChoice(player);
    computer = getComputerChoice();
    std::cout << "Computer chose: ";
    showChoice(computer);

    chooseWinner(player, computer);

    return 0;
}

char getUserChoice() {

    char player;
    do {
        std::cout << "Welcome to Rock-Paper-Scissors!" << std::endl;
        std::cout << "Please choose: r for Rock, p for Paper, s for Scissors" << std::endl;
        std::cout << "Enter your choice (r/p/s): ";
        std::cin >> player;
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char getComputerChoice() {
    srand(time(0));
    int num = rand() % 3;
    if (num == 0) return 'r';
    else if (num == 1) return 'p';
    else return 's';
}

void showChoice(char choice) {
 
    switch(choice) {
        case 'r':
            std::cout << "Rock." << std::endl;
            break;
        case 'p':
            std::cout << "Paper." << std::endl;
            break;
        case 's':
            std::cout << "Scissors." << std::endl;
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
    }
}

void chooseWinner(char player, char computer) {

    if (player == computer) {
        std::cout << "It's a tie!" << std::endl;
    } else if ((player == 'r' && computer == 's') ||
               (player == 'p' && computer == 'r') ||
               (player == 's' && computer == 'p')) {
        std::cout << "You win!" << std::endl;
    } else {
        std::cout << "Computer wins!" << std::endl;
    }
}
