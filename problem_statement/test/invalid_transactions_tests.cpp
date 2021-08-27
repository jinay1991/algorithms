///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/invalid_transactions.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace problem_statement
{
namespace
{
class InvalidTransactionsFixture : public ::testing::Test
{
  public:
    InvalidTransactionsFixture() : unit_{} {}

  protected:
    InvalidTransactions unit_;
};

template <typename T>
class InvalidTransactionsFixtureT : public InvalidTransactionsFixture, public ::testing::WithParamInterface<T>
{
};

struct TestTransactionParam
{
    // Given
    std::vector<std::string> transactions;

    // Then
    std::vector<std::string> invalid_transactions;
};

using InvalidTransactionsFixture_WithTransactions = InvalidTransactionsFixtureT<TestTransactionParam>;

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    ValidateTransaction,
    InvalidTransactionsFixture_WithTransactions,
    ::testing::Values(
        //                              transactions                      ,          (expected) invalid_transactions
        TestTransactionParam{{"alice,20,800,mtv", "alice,50,100,beijing" }, {"alice,20,800,mtv", "alice,50,100,beijing"}},
        TestTransactionParam{{"alice,20,800,mtv", "alice,50,1200,beijing"}, {"alice,50,1200,beijing"                   }},
        TestTransactionParam{{"alice,20,800,mtv", "bob,50,1200,mtv"      }, {"bob,50,1200,mtv"                         }}
));
// clang-format on

TEST_P(InvalidTransactionsFixture_WithTransactions,
       GetInvalidTransactions_GivenTypicalTransactions_ExpectInvalidTransactions)
{
    // Given
    const auto param = GetParam();

    // When
    const auto invalid_transactions = unit_.GetInvalidTransactions(param.transactions);

    // Then
    EXPECT_EQ(invalid_transactions, param.invalid_transactions);
}

}  // namespace
}  // namespace problem_statement
