#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void print_numbers(const vector<int>& numbers);
int calculate_mean(const vector<int>& numbers);
int calculate_smallest(const vector<int>& numbers);
int calculate_largest(const vector<int>& numbers);
int add_number(vector<int>& numbers);

int main() {

    char option = ' ';

    vector<int> numbers;

    while (option != 'Q') {

        cout << "Menu Options:" << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add numbers" << endl;
        cout << "M - Display mean of numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "C - Clear the list" << endl;
        cout << "Q - Quit" << endl;
        cout << "Please choose an option from the menu: ";

        cin >> option;
        option = toupper(option);

        switch (option) {
            case 'P':
                print_numbers(numbers);
                cout << endl;
                break;
            case 'A':
                add_number(numbers);
                cout << endl;
                break;
            case 'M':
                cout << "Mean: " << calculate_mean(numbers) << endl;
                cout << endl;
                break;
            case 'S':
                cout << "Smallest: " << calculate_smallest(numbers) << endl;
                cout << endl;
                break;
            case 'L':
                cout << "Largest: " << calculate_largest(numbers) << endl;
                cout << endl;
                break;
            case 'C':
                numbers.clear();
                cout << "List cleared." << endl;
                cout << endl;
                break;
            default:
                cout << "Invalid option. Please choose a valid option from the menu." << endl;
                cout << endl;
        }
    }
}

void print_numbers(const vector<int>& numbers) {
    if (numbers.empty()) {
        cout << "[] - the list is empty" << endl;
    } else {
        cout << "[ ";
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
}

int calculate_mean(const vector<int>& numbers) {
    if (numbers.empty()) {
        return 0; 
    }
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    return sum / numbers.size();
}

int calculate_smallest(const vector<int>& numbers) {
    if (numbers.empty()) {
        return 0; 
    }
    int smallest = numbers[0];
    for (int num : numbers) {
        if (num < smallest) {
            smallest = num;
        }
    }
    return smallest;
}

int calculate_largest(const vector<int>& numbers) {
    if (numbers.empty()) {
        return 0; 
    }
    int largest = numbers[0];
    for (int num : numbers) {
        if (num > largest) {
            largest = num;
        }
    }
    return largest;
}

int add_number(vector<int>& numbers) {
    int num;
    cout << "Enter a number to add: ";
    cin >> num;

    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid input. Please enter a valid number." << endl;
        return 0; 
    } else if (find(numbers.begin(), numbers.end(), num) != numbers.end()) {
        cout << "Number already exists in the list. Please enter a unique number." << endl;
        return 0; 
    }
    numbers.push_back(num);
    return num;
}