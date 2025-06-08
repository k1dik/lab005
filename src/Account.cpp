#include "Account.h"

Account::Account(std::string id, double balance)
    : id_(std::move(id)), balance_(balance) {}

std::string Account::getId() const {
    return id_;
}

double Account::getBalance() const {
    return balance_;
}

void Account::deposit(double amount) {
    if (amount > 0) balance_ += amount;
}

bool Account::withdraw(double amount) {
    if (amount > 0 && balance_ >= amount) {
        balance_ -= amount;
        return true;
    }
    return false;
}
