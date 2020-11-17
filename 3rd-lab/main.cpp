#include <iostream> //11 вариант (сумма индексов минимального и максимального элементов)
#include <limits.h>
#include "helper.h"

#pragma warning(disable : 4996)

void getSumOfIndex(const int* arr, int size) {
    int max = INT_MIN, min = INT_MAX, maxIndex, minIndex;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    std::cout << "Sum = " << minIndex + maxIndex << '\n';
}

int main() {
    srand(time(nullptr));
    {
        int arr[] = { 1, 43, 5794, 95, 5409, 20, 4, 5 };
        int size = sizeof(arr) / sizeof(*arr);
        printArray(arr, size);
        getSumOfIndex(arr, size);
    }
    {
        int n = getValue();
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 101;
        }
        printArray(arr, n);
        getSumOfIndex(arr, n);
        delete []arr;
    }
    {
        freopen("input.txt", "r", stdin);
        int n;
        while (std::cin >> n) {
            int* arr = new int[n];
            for (int i = 0; i < n; i++) {
                std::cin >> arr[i];
            }
            printArray(arr, n);
            getSumOfIndex(arr, n);
            delete []arr;
        }
    }
    return 0;
}