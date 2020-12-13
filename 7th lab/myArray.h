#ifndef MYARRAY_H
#define MYARRAY_H
#include "myException.h"
#include "myString.h"
#include <fstream>
#include <iomanip>
#include <iostream>

template<class T>
class MyArray {
public:
  MyArray();
  explicit MyArray(size_t size);
  MyArray(const MyArray<T>& arr);
  ~MyArray<T>();
  T* getData() const;
  void push_back(T& var);
  size_t find(const T& var, size_t index) const;
  [[nodiscard]] size_t size() const;
  [[nodiscard]] size_t capacity() const;
  T& operator[](size_t index);
  void resize(size_t n);
  void printScreen(size_t count);
  void printInFile(size_t count);

private:
  T* arr_;
  size_t capacity_{};
  size_t size_;
};

template<class T>
MyArray<T>::MyArray() {
  capacity_ = 10;
  size_ = 0;
  arr_ = new T[capacity_];
}
template<class T>
MyArray<T>::MyArray(const size_t size) {
  this->capacity_ = 2 * size;
  size_ = size;
  arr_ = new T[capacity_];
}
template<class T>
MyArray<T>::MyArray(const MyArray<T>& arr) {
  capacity_ = arr.capacity_;
  size_ = arr.size_;
  arr_ = new T[capacity_];
  for (size_t i = 0; i < capacity_; ++i) {
    arr_[i] = arr.arr_[i];
  }
}
template<class T>
MyArray<T>::~MyArray<T>() { delete[] arr_; }
template<class T>
T* MyArray<T>::getData() const { return arr_; }
template<class T>
void MyArray<T>::push_back(T& var) {
  if (size_ + 1 <= capacity_ - 1) {
    arr_[size_] = var;
    ++size_;
  } else {
    MyArray<T> a(*this);
    capacity_ *= 2;
    delete[] this->arr_;
    arr_ = new T[capacity_];
    for (size_t i = 0; i < a.getSize(); ++i) {
      arr_[i] = a[i];
    }
    arr_[size_] = var;
    ++size_;
  }
}

template<class T>
size_t MyArray<T>::find(const T& var, const size_t index) const {
  size_t dstIndex = -1;
  if (index >= size_) {
    return dstIndex;
  }
  for (size_t i = 0; i < size_; ++i) {
    if (var == this->arr_[i]) {
      dstIndex = i;
      break;
    }
  }
  return dstIndex;
}

template<class T>
size_t MyArray<T>::size() const { return size_; }

template<class T>
size_t MyArray<T>::capacity() const { return capacity_; }

template<class T>
T& MyArray<T>::operator[](const size_t index) {
  if (index > size_ - 1) {
    throw MyException("Out of range (in array)!\n");
  }
  return arr_[index];
}

template<class T>
void MyArray<T>::resize(size_t n) {
  MyArray temp = *this;
  delete[] arr_;
  capacity_ = n * 2;
  arr_ = new char[capacity_];
  for (int i = 0; i < n; ++i) {
    arr_[i] = temp.str_[i];
  }
  size_ = n;
}

template<class T>
void MyArray<T>::printScreen(size_t count) {
  for (size_t i = 0; i < size_; ++i) {
    if (i % count != 0) {
      std::cout << std::endl;
      std::cout << arr_[i] << " ";
    } else {
      std::cout << arr_[i] << " ";
    }
  }
  std::cout << '\n';
}

template<class T>
void MyArray<T>::printInFile(size_t count) {
  std::ofstream out("output.txt");
  size_t maxLengthPayAcc = 0;
  size_t maxLengthPayOrg = 0;
  size_t maxLengthRecipAcc = 0;
  size_t maxLengthRecipOrg = 0;
  size_t maxLengthPay = 0;
  for (size_t i = 0; i < count; ++i) {
    if (arr_[i].getPayAccLength() > maxLengthPayAcc) {
      maxLengthPayAcc = arr_[i].getPayAccLength();
    }
    if (arr_[i].getPayOrg().length() > maxLengthPayOrg) {
      maxLengthPayOrg = arr_[i].getPayOrg().length();
    }
    if (arr_[i].getRecipAccLength() > maxLengthRecipAcc) {
      maxLengthRecipAcc = arr_[i].getRecipAccLength();
    }
    if (arr_[i].getRecipOrg().length() > maxLengthRecipOrg) {
      maxLengthRecipOrg = arr_[i].getRecipOrg().length();
    }
    if (arr_[i].getPayLength() > maxLengthPay) {
      maxLengthPay = arr_[i].getPayLength();
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
    size_t lengthPayAcc = ((maxLengthPayAcc > payAccHeader.length()) ? maxLengthPayAcc : payAccHeader.length()) - arr_[i].getPayAccLength() + 3;
    size_t lengthPayOrg = ((maxLengthPayOrg > payOrgHeader.length()) ? maxLengthPayOrg : payOrgHeader.length()) - arr_[i].getPayOrg().length() + 3;
    size_t lengthRecipAcc = ((maxLengthRecipAcc > recipAccHeader.length()) ? maxLengthRecipAcc : recipAccHeader.length()) - arr_[i].getRecipAccLength() + 3;
    size_t lengthRecipOrg = ((maxLengthRecipOrg > recipOrgHeader.length()) ? maxLengthRecipOrg : recipOrgHeader.length()) - arr_[i].getRecipOrg().length() + 3;
    size_t lengthPay = ((maxLengthPay > payHeader.length()) ? maxLengthPay : payHeader.length()) - arr_[i].getPayLength() + 3;
    out << "| " << arr_[i].getPayAcc() << std::setw(lengthPayAcc) << " | " << arr_[i].getPayOrg() << std::setw(lengthPayOrg) << " | " << arr_[i].getRecipAcc()
        << std::setw(lengthRecipAcc) << " | " << arr_[i].getRecipOrg() << std::setw(lengthRecipOrg) << " | " << arr_[i].getPay() << std::setw(lengthPay) << " |\n";
  }
  for (int i = 0; i < sum; ++i) {
    out << '-';
  }
  out << '\n';
  out.close();
}

#endif