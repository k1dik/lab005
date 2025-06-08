#include "Transaction.h"

Transaction::Transaction(std::string id, double amount)
    : id_(id), amount_(amount) {}

std::string Transaction::getId() const {
    return id_;
}

double Transaction::getAmount() const {
    return amount_;
}
