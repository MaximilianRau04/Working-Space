#include <iostream> 
#include <vector>

using namespace std;

int main() {
    
    vector<int> numbers = {1, 2, 3, 4, 5};

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << '\n'; // Output: 1 2 3 4 5
    }

    numbers.insert(numbers.begin(), 10); // Insert 10 at index 1
    numbers.erase(numbers.begin()); // Remove the element at index 1

    numbers.push_back(6); // Add 6 to the end of the vector
    numbers.pop_back(); // Remove the last element (6)
    cout << numbers[0] << '\n'; // Output: 1
    cout << numbers.size() << '\n'; // Output: 6
    cout << numbers.capacity() << '\n'; // Output: 10
    numbers.shrink_to_fit(); // Reduce capacity to fit size
    cout << numbers.capacity() << '\n'; // Output: 5

    return 0;
}