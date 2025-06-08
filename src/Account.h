#pragma once

#include <string>

class Account {
public:
    Account(std::string id, double balance = 0.0);
    std::string getId() const;
    double getBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);

private:
    std::string id_;
    double balance_;
};
