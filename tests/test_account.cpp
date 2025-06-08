#include "Account.h"
#include <gtest/gtest.h>

TEST(AccountTest, DepositIncreasesBalance) {
    Account acc("123", 100.0);
    acc.deposit(50.0);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 150.0);
}

TEST(AccountTest, WithdrawDecreasesBalance) {
    Account acc("123", 100.0);
    bool success = acc.withdraw(70.0);
    EXPECT_TRUE(success);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 30.0);
}

TEST(AccountTest, WithdrawFailsIfInsufficientFunds) {
    Account acc("123", 50.0);
    bool success = acc.withdraw(70.0);
    EXPECT_FALSE(success);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 50.0);
}
