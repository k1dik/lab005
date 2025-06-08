#pragma once

#include <string>
#include <memory>

class Account;

class Transaction {
public:
    Transaction(std::shared_ptr<Account> from, std::shared_ptr<Account> to, double amount);
    bool execute();

private:
    std::shared_ptr<Account> from_;
    std::shared_ptr<Account> to_;
    double amount_;
};
