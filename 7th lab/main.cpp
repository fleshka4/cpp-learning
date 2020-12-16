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

void printInFile(MyArray<Payment>& arr, size_t count) {
  std::ofstream out("output.txt");
  size_t maxLengthPayAcc = 0;
  size_t maxLengthPayOrg = 0;
  size_t maxLengthRecipAcc = 0;
  size_t maxLengthRecipOrg = 0;
  size_t maxLengthPay = 0;
  for (size_t i = 0; i < count; ++i) {
    if (arr[i].getPayAccLength() > maxLengthPayAcc) {
      maxLengthPayAcc = arr[i].getPayAccLength();
    }
    if (arr[i].getPayOrg().length() > maxLengthPayOrg) {
      maxLengthPayOrg = arr[i].getPayOrg().length();
    }
    if (arr[i].getRecipAccLength() > maxLengthRecipAcc) {
      maxLengthRecipAcc = arr[i].getRecipAccLength();
    }
    if (arr[i].getRecipOrg().length() > maxLengthRecipOrg) {
      maxLengthRecipOrg = arr[i].getRecipOrg().length();
    }
    if (arr[i].getPayLength() > maxLengthPay) {
      maxLengthPay = arr[i].getPayLength();
    }
  }
  MyString payAccHeader = "Payer's current account";
  MyString payOrgHeader = "Payer's organization";
  MyString recipAccHeader = "Recipient's current account";
  MyString recipOrgHeader = "Recipient's organization";
  MyString payHeader = "Payment";
  size_t lengthPayAccHeader = (maxLengthPayAcc < payAccHeader.length()) ? 0 : (maxLengthPayAcc - payAccHeader.length()) + 3;
  size_t lengthPayOrgHeader = (maxLengthPayOrg < payOrgHeader.length()) ? 0 : (maxLengthPayOrg - payOrgHeader.length()) + 3;
  size_t lengthRecipAccHeader = (maxLengthRecipAcc < recipAccHeader.length()) ? 0 : (maxLengthRecipAcc - recipAccHeader.length()) + 3;
  size_t lengthRecipOrgHeader = (maxLengthRecipOrg < recipOrgHeader.length()) ? 0 : (maxLengthRecipOrg - recipOrgHeader.length()) + 3;
  size_t lengthPayHeader = (maxLengthPay < payHeader.length()) ? 0 : (maxLengthPay - payHeader.length()) + 3;
  size_t sum = payAccHeader.length() + payOrgHeader.length() + recipAccHeader.length() + recipOrgHeader.length() + payHeader.length()
               + ((lengthPayAccHeader == 0) ? 0 : lengthPayAccHeader - 3) + ((lengthPayOrgHeader == 0) ? 0 : lengthPayOrgHeader - 3)
               + ((lengthRecipAccHeader == 0) ? 0 : lengthRecipAccHeader - 3) + ((lengthRecipOrgHeader == 0) ? 0 : lengthRecipOrgHeader - 3)
               + ((lengthPayHeader == 0) ? 0 : lengthPayHeader - 3) + 16;
  out.precision(255);
  for (int i = 0; i < sum; ++i) {
    out << '-';
  }
  out << '\n';
  out << "| " << payAccHeader << std::setw(lengthPayAccHeader) << " | " << payOrgHeader << std::setw(lengthPayOrgHeader) << " | " << recipAccHeader
      << std::setw(lengthRecipAccHeader) << " | " << recipOrgHeader << std::setw(lengthRecipOrgHeader) << " | " << payHeader << std::setw(lengthPayHeader) << " |\n";
  for (int i = 0; i < sum; ++i) {
    out << '-';
  }
  out << '\n';
  for (size_t i = 0; i < count; ++i) {
    size_t lengthPayAcc = ((maxLengthPayAcc > payAccHeader.length()) ? maxLengthPayAcc : payAccHeader.length()) - arr[i].getPayAccLength() + 3;
    size_t lengthPayOrg = ((maxLengthPayOrg > payOrgHeader.length()) ? maxLengthPayOrg : payOrgHeader.length()) - arr[i].getPayOrg().length() + 3;
    size_t lengthRecipAcc = ((maxLengthRecipAcc > recipAccHeader.length()) ? maxLengthRecipAcc : recipAccHeader.length()) - arr[i].getRecipAccLength() + 3;
    size_t lengthRecipOrg = ((maxLengthRecipOrg > recipOrgHeader.length()) ? maxLengthRecipOrg : recipOrgHeader.length()) - arr[i].getRecipOrg().length() + 3;
    size_t lengthPay = ((maxLengthPay > payHeader.length()) ? maxLengthPay : payHeader.length()) - arr[i].getPayLength() + 3;
    out << "| " << arr[i].getPayAcc() << std::setw(lengthPayAcc) << " | " << arr[i].getPayOrg() << std::setw(lengthPayOrg) << " | " << arr[i].getRecipAcc()
        << std::setw(lengthRecipAcc) << " | " << arr[i].getRecipOrg() << std::setw(lengthRecipOrg) << " | " << arr[i].getPay() << std::setw(lengthPay) << " |\n";
  }
  for (int i = 0; i < sum; ++i) {
    out << '-';
  }
  out << '\n';
  out.close();
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
    printInFile(payments, payments.size());
    in.close();
  } catch (MyException& ex) {
    std::cerr << ex.what();
  } catch (...) {
    std::cerr << "Unknown error!\n";
  }
  return 0;
}
