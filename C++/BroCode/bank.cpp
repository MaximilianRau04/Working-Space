#include <iostream>

void showBalance(double balance);
double deposit();
double withdraw(double balance);


int main() {
    
    double balance = 0;
    int choice = 0;

    while (true) {
        std::cout << "\nBanking System Menu:\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1,2,3,4): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                showBalance(balance);
                break;
            case 2:
                balance += deposit();
                showBalance(balance);
                break;
            case 3:
                balance -= withdraw(balance);
                showBalance(balance);
                break;
            case 4:
                std::cout << "Thank you for using our banking system!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

void showBalance(double balance) {
    std::cout << "Current balance: $" << balance << std::endl;
}

double deposit() {
    double amount;
    std::cout << "Enter deposit amount: $";
    std::cin >> amount;
    return amount;
}

double withdraw(double balance) {
    double amount;
    std::cout << "Enter withdrawal amount: $";
    std::cin >> amount;
    if (amount > balance) {
        std::cout << "Insufficient funds. Withdrawal denied." << std::endl;
        return balance;
    }
    return amount;
}