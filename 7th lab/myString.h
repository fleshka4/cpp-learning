#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

size_t strLength(const char* str);

class MyString {
public:
  MyString();
  MyString(const char* str);
  MyString(const MyString& other);
  MyString(const MyString& other, size_t pos, size_t len = npos);
  MyString(MyString&& other) noexcept;
  ~MyString();
  [[nodiscard]] size_t length() const;
  [[nodiscard]] size_t size() const;
  void push_back(char ch);
  char* begin() noexcept;
  char* end() noexcept;
  char* rbegin() noexcept;
  char* rend() noexcept;
  [[nodiscard]] char* getStr() const;
  [[nodiscard]] bool empty() const noexcept;
  void resize(size_t n);
  MyString& operator=(const char* other);
  MyString& operator=(const MyString& other);
  MyString& operator+=(char ch);
  MyString& operator+=(const char* other);
  MyString& operator+=(const MyString& other);
  bool operator==(const MyString& other) const;
  bool operator!=(const MyString& other) const;
  char& operator[](size_t index);
  friend std::ostream& operator<<(std::ostream& os, const MyString& str);
  friend std::istream& operator>>(std::istream& is, MyString& str);
  friend MyString operator+(const MyString& lhs, const MyString& rhs);
  friend MyString operator+(const MyString& lhs, const char* rhs);
  friend MyString operator+(const char* lhs, const MyString& rhs);
  friend std::istream& getline(std::istream& is, MyString& str);

private:
  char* str_;
  char* begin_ = nullptr;
  char* end_ = nullptr;
  size_t length_;
  static const size_t npos = -1;
  static const size_t CIN_LIM = 100000;
};

#endif