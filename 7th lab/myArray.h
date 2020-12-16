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

private:
  T* arr_;
  size_t capacity_;
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

#endif
