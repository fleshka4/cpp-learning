#ifndef PAYMENT_H
#define PAYMENT_H

#include "myString.h"
#include <iostream>

class Payment {
public:
  Payment();
  Payment(const size_t& payAcc, const MyString& payOrg, const size_t& recipAcc,
          const MyString& recipOrg, const size_t& pay);
  Payment(const Payment& other);
  ~Payment();
  Payment& operator=(const Payment& other);
  bool operator==(const Payment& rhs) const;
  friend bool operator!=(const Payment& lhs, const Payment& rhs);
  friend bool operator<(const Payment& lhs, const Payment& rhs);
  bool operator>(const Payment& rhs) const;
  bool operator<=(const Payment& rhs) const;
  bool operator>=(const Payment& rhs) const;
  Payment& operator++();
  friend Payment operator++(Payment& payment, int);
  friend std::istream& operator>>(std::istream& is, Payment& payment);
  [[nodiscard]] size_t getPayAccLength() const;
  [[nodiscard]] const MyString& getPayOrg() const;
  [[nodiscard]] size_t getRecipAccLength() const;
  [[nodiscard]] const MyString& getRecipOrg() const;
  [[nodiscard]] size_t getPayLength() const;
  [[nodiscard]] size_t getPayAcc() const;
  [[nodiscard]] size_t getRecipAcc() const;
  [[nodiscard]] double getPay() const;
  friend std::ostream& operator<<(std::ostream& os, const Payment& payment);

private:
  size_t payAcc_;
  MyString payOrg_;
  size_t recipAcc_;
  MyString recipOrg_;
  size_t pay_;
};

#endif
