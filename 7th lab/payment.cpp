#include "payment.h"
#include "myException.h"

Payment::Payment() {
  payAcc_ = 0;
  recipAcc_ = 0;
  pay_ = 0;
}

Payment::Payment(const size_t& payAcc, const MyString& payOrg,
                 const size_t& recipAcc, const MyString& recipOrg,
                 const size_t& pay) {
  payAcc_ = payAcc;
  payOrg_ = payOrg;
  recipAcc_ = recipAcc;
  recipOrg_ = recipOrg;
  pay_ = pay;
}

Payment::Payment(const Payment& other) {
  this->payAcc_ = other.payAcc_;
  this->payOrg_ = other.payOrg_;
  this->recipAcc_ = other.recipAcc_;
  this->recipOrg_ = other.recipOrg_;
  this->pay_ = other.pay_;
}

Payment::~Payment() = default;

Payment& Payment::operator=(const Payment& other) {
  if (&other == this) {
    return *this;
  }
  this->payOrg_ = other.payOrg_;
  this->recipOrg_ = other.recipOrg_;
  this->payAcc_ = other.payAcc_;
  this->recipAcc_ = other.recipAcc_;
  this->pay_ = other.pay_;
}

bool Payment::operator==(const Payment& rhs) const {
  return recipAcc_ == rhs.recipAcc_ && payAcc_ == rhs.payAcc_ &&
         recipOrg_ == rhs.recipOrg_ && payOrg_ == rhs.payOrg_ &&
         pay_ == rhs.pay_;
}

bool operator!=(const Payment& lhs, const Payment& rhs) { return !(rhs == lhs); }

bool operator<(const Payment& lhs, const Payment& rhs) {
  return lhs.pay_ < rhs.pay_;
}
bool Payment::operator>(const Payment& rhs) const {
  return rhs < *this;
}
bool Payment::operator<=(const Payment& rhs) const {
  return !(rhs < *this);
}
bool Payment::operator>=(const Payment& rhs) const {
  return !(*this < rhs);
}

Payment& Payment::operator++() {
  this->pay_++;
  return *this;
}

Payment operator++(Payment& payment, int) {
  Payment newPayment(payment);
  payment.pay_++;
  return newPayment;
}

std::istream& operator>>(std::istream& is, Payment& payment) {
  is >> payment.payAcc_;
  if ((!is) || (payment.payAcc_ == -1) || (is.bad())) throw MyException("Input error (payAcc)!\n");
  is >> payment.payOrg_;
  is >> payment.recipAcc_;
  if ((!is) || (payment.recipAcc_ == -1) || (is.bad())) throw MyException("Input error(recipAcc)!\n");
  is >> payment.recipOrg_;
  is >> payment.pay_;
  if ((!is) || (payment.pay_ == -1) || (is.bad())) throw MyException("Input error(pay)!\n");
  return is;
}

std::ostream& operator<<(std::ostream& os, const Payment& payment) {
  os << "payAcc_: " << payment.payAcc_ << " payOrg_: " << payment.payOrg_ << " recipAcc_: " << payment.recipAcc_
     << " recipOrg_: " << payment.recipOrg_ << " pay_: " << payment.pay_;
  return os;
}

size_t Payment::getPayAccLength() const {
  size_t amount = 0;
  size_t temp = payAcc_;
  while (temp > 0) {
    amount++;
    temp /= 10;
  }
  return amount;
}

const MyString& Payment::getPayOrg() const {
  return payOrg_;
}
size_t Payment::getRecipAccLength() const {
  size_t amount = 0;
  size_t temp = recipAcc_;
  while (temp > 0) {
    amount++;
    temp /= 10;
  }
  return amount;
}
const MyString& Payment::getRecipOrg() const {
  return recipOrg_;
}
size_t Payment::getPayLength() const {
  size_t amount = 0;
  size_t temp = pay_;
  while (temp > 0) {
    amount++;
    temp /= 10;
  }
  return amount;
}
size_t Payment::getPayAcc() const {
  return payAcc_;
}
size_t Payment::getRecipAcc() const {
  return recipAcc_;
}
double Payment::getPay() const {
  return pay_;
}
