#include "Transaction.h"
#include "Account.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

class MockTransaction : public Transaction {
public:
    MOCK_METHOD(void, SaveToDataBase, (Account& from, Account& to, int sum), (override));
};

TEST(TransactionTest, MakeTransactionWorks) {
    Account from(1, 5000);
    Account to(2, 3000);

    MockTransaction trans;
    EXPECT_CALL(trans, SaveToDataBase(::testing::_, ::testing::_, ::testing::_)).Times(1);

    bool result = trans.Make(from, to, 500);
    EXPECT_TRUE(result);
}
