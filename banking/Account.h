#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
    Account(std::string owner, double balance);
    virtual ~Account() = default;

    virtual void deposit(double amount);
    virtual bool withdraw(double amount);

    double getBalance() const;
    std::string getOwner() const;

private:
    std::string owner_;
    double balance_;
};

#endif // ACCOUNT_H
