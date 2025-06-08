#include "Transaction.h"
#include "Account.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

class MockAccount : public Account {
public:
    MockAccount() : Account("mock", 100.0) {}
    MOCK_METHOD(double, getBalance, (), (const, override));
    MOCK_METHOD(void, deposit, (double amount), (override));
    MOCK_METHOD(bool, withdraw, (double amount), (override));
    MOCK_METHOD(std::string, getId, (), (const, override));
};

// Но в данном случае проще тестировать Transaction с настоящими Account:

TEST(TransactionTest, SuccessfulTransaction) {
    auto from = std::make_shared<Account>("from", 100.0);
    auto to = std::make_shared<Account>("to", 50.0);
    Transaction t(from, to, 70.0);
    bool result = t.execute();
    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(from->getBalance(), 30.0);
    EXPECT_DOUBLE_EQ(to->getBalance(), 120.0);
}

TEST(TransactionTest, FailTransactionInsufficientFunds) {
    auto from = std::make_shared<Account>("from", 30.0);
    auto to = std::make_shared<Account>("to", 50.0);
    Transaction t(from, to, 70.0);
    bool result = t.execute();
    EXPECT_FALSE(result);
    EXPECT_DOUBLE_EQ(from->getBalance(), 30.0);
    EXPECT_DOUBLE_EQ(to->getBalance(), 50.0);
}
