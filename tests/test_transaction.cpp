#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Transaction.h"

TEST(TransactionTest, GettersReturnCorrectValues) {
    Transaction t("tx123", 200.0);
    EXPECT_EQ(t.getId(), "tx123");
    EXPECT_DOUBLE_EQ(t.getAmount(), 200.0);
}
