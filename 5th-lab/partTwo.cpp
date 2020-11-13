#include <iostream>
#pragma warning(disable : 4996)

int getMaxSum(int* const* arr, const int& size) {
    int sum = 0, max = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[size - 1 - i][i];
    }
    max = sum;
    sum = 0;
    for (int i = 1; i < size; i++) {
        for (int j = i; j < size; j++) {
            sum += arr[size - 1 - j][j - i];
        }
        if (sum > max) max = sum;
        sum = 0;
    }
    for (int i = 1; i < size; i++) {
        for (int j = i; j < size; j++) {
            sum += arr[j][size + i - j - 1];
        }
        if (sum > max) max = sum;
        sum = 0;
    }
    return max;
}

void partTwo() {
    freopen("input.txt", "r", stdin);
    int size;
    std::cin >> size;
    int** doubleArray = new int* [size];
    for (int i = 0; i < size; i++) {
        doubleArray[i] = new int[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> doubleArray[i][j];
            std::cout << doubleArray[i][j] << "\t";
        }
        std::cout << '\n';
    }
    fclose(stdin);
    freopen("output.txt", "w", stdout);
    std::cout << getMaxSum(doubleArray, size);
    fclose(stdout);
}