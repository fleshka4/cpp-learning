#include "myException.h"
#include "myString.h"

MyException::MyException(const char* text) {
  text_ = new char[strLength(text) + 1];
  for (int i = 0; i < strLength(text); ++i) {
    text_[i] = text[i];
  }
  text_[strLength(text)] = '\0';
}

[[maybe_unused]] MyException::MyException(const MyException& e) {
  text_ = new char[strLength(e.text_) + 1];
  for (int i = 0; i < strLength(e.text_); ++i) {
    text_[i] = e.text_[i];
  }
  text_[strLength(e.text_)] = '\0';
}

MyException::~MyException() noexcept {
  delete[] text_;
}

const char* MyException::what() const noexcept {
  return text_;
}