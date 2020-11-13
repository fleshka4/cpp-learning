#include <iostream>

int getValue() {
    std::cout << "Enter the number (will returned number module): ";
    int n;
    while (!(std::cin >> n))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "You didn't enter an integer! ";
    }
    return abs(n);
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << '\t';
    }
    std::cout << '\n';
}