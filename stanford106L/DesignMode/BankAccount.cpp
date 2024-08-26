#include "BankAccount.h"
#include <iostream>

class Account::Impl {
public:
    Impl(double balance) : _balance(balance) {}
    void deposit() {
        std::cout << "Hello World\n";
    }

private:
    double _balance;
};

Account::Account(double balance) : aImpl(std::make_unique<Impl>(balance)) {}
Account::~Account() = default;

void Account::deposit() { aImpl->deposit(); }
