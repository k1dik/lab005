#include "Account.h"
#include "gtest/gtest.h"

TEST(AccountTest, ChangeBalanceAfterLock) {
    Account acc(1, 1000);
    acc.Lock();
    acc.ChangeBalance(500);
    EXPECT_EQ(acc.GetBalance(), 1500);
}
