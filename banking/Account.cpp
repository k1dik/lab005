#include "Account.h"

Account::Account(std::string owner, double balance)
    : owner_(owner), balance_(balance) {}

void Account::deposit(double amount) {
    balance_ += amount;
}

bool Account::withdraw(double amount) {
    if (balance_ >= amount) {
        balance_ -= amount;
        return true;
    }
    return false;
}

double Account::getBalance() const {
    return balance_;
}

std::string Account::getOwner() const {
    return owner_;
}
