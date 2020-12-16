#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>

class MyException : public std::exception {
public:
  explicit MyException(const char* text);
  [[maybe_unused]] MyException(const MyException& e);
  ~MyException() noexcept override;
  [[nodiscard]] const char* what() const noexcept override;

private:
  char* text_;
};

#endif