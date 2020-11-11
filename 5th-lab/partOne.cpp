#include <bits/stdc++.h>

template <typename T>
int getNumberOfSortedRows(const T doubleArray, const int numOfRows, const int numOfColumns) {
    int count = 0;
    bool flag = true;
    for (int i = 0; i < numOfColumns; i++) {
        for (int j = 1; j < numOfRows; j++) {
            if (doubleArray[i][j - 1] >= doubleArray[i][j]) {
                flag = false;
                break;
            }
        }
        if (flag) count++;
        flag = true;
    }
    return count;
}

void partOne() {
    unsigned int const numOfRows = 3;
    unsigned int const numOfColumns = 4;
    int doubleArray[numOfRows][numOfColumns] = {
        {45, 439, 584, 1000},
        {3, 0, -3, 4},
        {1, 2, 3, 4}
    };
    std::cout << "Number of sorted rows: " << getNumberOfSortedRows(doubleArray, numOfRows, numOfColumns) << std::endl;
}