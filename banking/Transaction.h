#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
public:
    Transaction(std::string id, double amount);
    virtual ~Transaction() = default;

    virtual std::string getId() const;
    virtual double getAmount() const;

private:
    std::string id_;
    double amount_;
};

#endif // TRANSACTION_H
