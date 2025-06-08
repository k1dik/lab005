#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Account.h"

using ::testing::Return;
using ::testing::_;

// Пример mock-класса (если нужно)
// В данном простом случае можно тестировать напрямую класс Account

TEST(AccountTest, DepositIncreasesBalance) {
    Account acc("John", 100);
    acc.deposit(50);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 150);
}

TEST(AccountTest, WithdrawDecreasesBalance) {
    Account acc("John", 100);
    bool success = acc.withdraw(70);
    EXPECT_TRUE(success);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 30);
}

TEST(AccountTest, WithdrawFailsIfInsufficientFunds) {
    Account acc("John", 100);
    bool success = acc.withdraw(150);
    EXPECT_FALSE(success);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 100);
}
