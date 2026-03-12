#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {

    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while(running) {
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)) {
            std::cout << "Player wins!" << '\n';
            running = false;
            break;
        }
        if (checkTie(spaces)) {
            std::cout << "It's a tie!" << '\n';
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)) {
            std::cout << "Computer wins!" << '\n';
            running = false;
            break;
        }
        if (checkTie(spaces)) {
            std::cout << "It's a tie!" << '\n';
            running = false;
            break;
        }
    }

    return 0;
}

void drawBoard(char *spaces) {
    std::cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << " \n";
    std::cout << "---|---|---\n";
    std::cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << " \n";
    std::cout << '\n';
}

void playerMove(char *spaces, char player) {
    int number;
    do {
        std::cout << "Enter a number (1-9) to place your " << player << ": ";
        std::cin >> number;
        number--;

        if (spaces[number] != ' ') {
            spaces[number] = player;
            break;
        } 
    } while (number < 0 || number > 8);
    spaces[number] = player;
}

void computerMove(char *spaces, char computer) {
    int number;
    srand(time(0));

    while(true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer) {
    
    if ((spaces[0] == player && spaces[1] == player && spaces[2] == player) ||
        (spaces[3] == player && spaces[4] == player && spaces[5] == player) ||
        (spaces[6] == player && spaces[7] == player && spaces[8] == player) ||
        (spaces[0] == player && spaces[3] == player && spaces[6] == player) ||
        (spaces[1] == player && spaces[4] == player && spaces[7] == player) ||
        (spaces[2] == player && spaces[5] == player && spaces[8] == player) ||
        (spaces[0] == player && spaces[4] == player && spaces[8] == player) ||
        (spaces[2] == player && spaces[4] == player && spaces[6] == player)) {
        return true;
    }

    return false;
}

bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    return true;
}