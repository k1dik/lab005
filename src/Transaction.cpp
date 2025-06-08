#include "Transaction.h"
#include "Account.h"

Transaction::Transaction(std::shared_ptr<Account> from, std::shared_ptr<Account> to, double amount)
    : from_(from), to_(to), amount_(amount) {}

bool Transaction::execute() {
    if (from_ && to_ && amount_ > 0 && from_->withdraw(amount_)) {
        to_->deposit(amount_);
        return true;
    }
    return false;
}
