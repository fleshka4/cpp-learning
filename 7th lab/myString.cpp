#include "myString.h"
#include "myException.h"
#include <iostream>

size_t strLength(const char* str) {
  if (str == nullptr) {
    return 0;
  }
  int counter = 0;
  while (str[counter] != '\0') {
    counter++;
  }
  return counter;
}

MyString operator+(const MyString& lhs, const MyString& rhs) {
  MyString newStr;
  newStr.length_ = lhs.length_ + rhs.length_;
  newStr.str_ = new char[newStr.length_ + 1];
  int i = 0;
  for (; i < lhs.length_; i++) {
    newStr.str_[i] = lhs.str_[i];
  }
  for (int j = 0; j < rhs.length_; j++, i++) {
    newStr.str_[i] = rhs.str_[j];
  }
  newStr.str_[lhs.length_ + rhs.length_] = '\0';
  return newStr;
}

MyString operator+(const MyString& lhs, const char* rhs) {
  MyString newStr;
  newStr.length_ = lhs.length_ + strLength(rhs);
  newStr.str_ = new char[newStr.length_ + 1];
  int i = 0;
  for (; i < lhs.length_; i++) {
    newStr.str_[i] = lhs.str_[i];
  }
  for (int j = 0; j < strLength(rhs); j++, i++) {
    newStr.str_[i] = rhs[j];
  }
  newStr.str_[lhs.length_ + strLength(rhs)] = '\0';
  return newStr;
}

MyString operator+(const char* lhs, const MyString& rhs) {
  MyString newStr;
  newStr.length_ = strLength(lhs) + rhs.length_;
  newStr.str_ = new char[newStr.length_ + 1];
  int i = 0;
  for (; i < strLength(lhs); i++) {
    newStr.str_[i] = lhs[i];
  }
  for (int j = 0; j < rhs.length_; j++, i++) {
    newStr.str_[i] = rhs.str_[j];
  }
  newStr.str_[strLength(lhs) + rhs.length_] = '\0';
  return newStr;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
  os << str.str_;
  return os;
}

std::istream& getline(std::istream& is, MyString& str) {
  char temp[MyString::CIN_LIM];
  is.get(temp, MyString::CIN_LIM);
  if (is)
    str = temp;
  while (is && is.get() != '\n')
    continue;
  return is;
}

std::istream& operator>>(std::istream& is, MyString& inString) {
  MyString temp;
  char chTemp = is.get();
  while ((chTemp == ' ') || (chTemp == '\n')) {
    chTemp = is.get();
  }
  is.unget();
  char symbol;
  while (true) {
    symbol = is.get();
    if (symbol == ' ' || symbol == '\n') {
      break;
    }
    temp += symbol;
  }
  inString = temp;
  return is;
}

MyString::MyString() {
  str_ = nullptr;
  length_ = 0;
}

MyString::MyString(const char* str) {
  length_ = strLength(str);
  this->str_ = new char[length_ + 1];
  for (int i = 0; i < length_; i++) {
    this->str_[i] = str[i];
  }
  this->str_[length_] = '\0';
}

MyString::MyString(const MyString& other) {
  length_ = strLength(other.str_);
  this->str_ = new char[length_ + 1];
  for (int i = 0; i < length_; i++) {
    this->str_[i] = other.str_[i];
  }
  this->str_[length_] = '\0';
}

MyString::MyString(const MyString& other, size_t pos, size_t len) {
  if (len == -1) {
    len = other.length_ - pos;
  }
  this->length_ = len;
  this->str_ = new char[this->length_ + 1];
  for (int i = 0; i < length_; ++i) {
    this->str_[i] = other.str_[pos + i];
  }
  this->str_[length_] = '\0';
}

MyString::MyString(MyString&& other) noexcept {
  this->length_ = other.length_;
  this->str_ = other.str_;
  other.str_ = nullptr;
}

MyString::~MyString() {
  delete[] this->str_;
  delete[] this->begin_;
  delete[] this->end_;
}

size_t MyString::length() const { return length_; }

size_t MyString::size() const { return length_; }

void MyString::push_back(const char ch) { operator+=(ch); }

char* MyString::begin() noexcept {
  begin_ = new char[2];
  begin_[0] = str_[0];
  begin_[1] = '\0';
  return begin_;
}

char* MyString::end() noexcept {
  end_ = new char[2];
  end_[0] = str_[length_ - 1];
  end_[1] = '\0';
  return end_;
}

char* MyString::rbegin() noexcept { return end(); }

char* MyString::rend() noexcept { return begin(); }

bool MyString::empty() const noexcept { return length_ == 0; }

void MyString::resize(size_t n) {
  MyString temp = *this;
  delete[] str_;
  str_ = new char[n + 1];
  for (int i = 0; i < n; ++i) {
    str_[i] = temp.str_[i];
  }
  str_[n] = '\0';
  length_ = n;
}

MyString& MyString::operator=(const char* other) {
  if (this->str_ == other) {
    return *this;
  }
  delete[] str_;
  length_ = strLength(other);
  this->str_ = new char[length_ + 1];
  for (int i = 0; i < length_; i++) {
    this->str_[i] = other[i];
  }
  this->str_[length_] = '\0';
  return *this;
}

MyString& MyString::operator=(const MyString& other) {
  if (&other == this) {
    return *this;
  }
  delete[] str_;
  length_ = other.length_;
  this->str_ = new char[length_ + 1];
  for (int i = 0; i < length_; i++) {
    this->str_[i] = other.str_[i];
  }
  this->str_[length_] = '\0';
  return *this;
}

MyString& MyString::operator+=(const char ch) {
  MyString temp = *(this);
  length_++;
  delete[] str_;
  this->str_ = new char[length_ + 1];
  for (int i = 0; i < length_ - 1; ++i) {
    this->str_[i] = temp.str_[i];
  }
  str_[length_ - 1] = ch;
  str_[length_] = '\0';
  return *(this);
}

MyString& MyString::operator+=(const char* other) {
  MyString temp = *this;
  this->str_ = new char[length_ + strLength(other) + 1];
  size_t i = 0;
  for (; i < length_; ++i) {
    this->str_[i] = temp[i];
  }
  for (size_t j = 0; j < strLength(other); j++, ++i) {
    this->str_[i] = other[j];
  }
  length_ += strLength(other);
  str_[length_] = '\0';
  return *(this);
}

MyString& MyString::operator+=(const MyString& other) {
  MyString temp = *(this);
  delete[] str_;
  this->str_ = new char[length_ + other.length_ + 1];
  size_t i = 0;
  for (; i < length_; ++i) {
    this->str_[i] = temp[i];
  }
  for (size_t j = 0; j < other.length_; j++, ++i) {
    this->str_[i] = other.str_[j];
  }
  length_ += other.length_;
  str_[length_] = '\0';
  return *(this);
}

bool MyString::operator==(const MyString& other) const {
  if (this->length_ != other.length_) {
    return false;
  }
  for (int i = 0; i < length_; i++) {
    if (this->str_[i] != other.str_[i]) {
      return false;
    }
  }
  return true;
}

bool MyString::operator!=(const MyString& other) const {
  return !(this->operator==(other));
}

char& MyString::operator[](size_t index) {
  if (index > length_ - 1) {
    throw MyException("Out of range(in string)!\n");
  }
  return this->str_[index];
}

char* MyString::getStr() const {
  return str_;
}