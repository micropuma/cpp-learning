#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <memory>

class Account {
public:
    Account(double balance); 
    ~Account();

    void deposit();

private:
    class Impl;
    std::unique_ptr<Impl> aImpl;
};

#endif
 
