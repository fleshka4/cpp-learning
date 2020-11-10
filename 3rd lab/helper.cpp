#include <bits/stdc++.h>

int getValue() {
    std::cout << "Enter the number: ";
    int n;
    while (!(std::cin >> n))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');

        std::cout << "Something went wrong! ";
    }
    return abs(n);
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << '\t';
    }
    std::cout << '\n';
}
