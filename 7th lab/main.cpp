#include "myArray.h"
#include "payment.h"
#include <fstream>
#include <iostream>

template<class T>
void sort(T& t, int size) {
  int j;
  for (int i = 0; i < size; i++) {
    j = i - 1;
    while ((j >= 0) && (t[j] > t[j + 1])) {
      std::swap(t[j], t[j + 1]);
      j--;
    }
  }
}

size_t max(MyArray<Payment>& payments) {
  Payment maxPayment;
  size_t indexMaxPayment = 0;
  for (size_t i = 0; i < payments.size(); ++i) {
    if (payments[i] >= maxPayment) {
      maxPayment = payments[i];
      indexMaxPayment = i;
    }
  }
  return indexMaxPayment;
}

int main() {
  try {
    MyString filename;
    std::cout << "Enter the name of file for reading:";
    std::cout.precision(255555);
    std::cin >> filename;
    std::ifstream in(filename.getStr());
    if (!in) {
      throw MyException("File is not open!\n");
    }
    int n;
    std::cout << "Enter the number of payments:";
    std::cin >> n;
    if (n <= 0) throw MyException("Incorrect number of payments!\n");
    MyArray<Payment> payments(n);
    in.precision(255555);
    for (int i = 0; i < payments.size(); ++i) {
      in >> payments[i];
    }
    sort(payments, payments.size());
    std::cout << "max: " << payments[max(payments)] << '\n';
    payments.printInFile(payments.size());
    in.close();
  } catch (MyException& ex) {
    std::cerr << ex.what();
  }
  return 0;
}