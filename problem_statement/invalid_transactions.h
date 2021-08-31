///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
/// @ref https://leetcode.com/problems/invalid-transactions/
///
#ifndef PROBLEM_STATEMENT_VALIDATE_TRANSACTION_H
#define PROBLEM_STATEMENT_VALIDATE_TRANSACTION_H

#include <chrono>
#include <cstdint>
#include <string>
#include <vector>

namespace problem_statement
{

struct Transaction
{
    std::string name{};
    std::chrono::minutes time{0U};
    std::uint32_t amount{0U};
    std::string city{};
};

class InvalidTransactions
{
  public:
    InvalidTransactions();

    std::vector<std::string> GetInvalidTransactions(const std::vector<std::string>& transactions) noexcept;

  private:
    Transaction ParseTransaction(const std::string& transaction) const noexcept;
    bool IsTransactionAmountInvalid(const Transaction& parsed_transaction) const noexcept;
    bool IsTransactionRepeated(const Transaction& parsed_transaction) const noexcept;
    bool IsTransactionInvalid(const std::string& transaction) const noexcept;

    std::vector<Transaction> previous_transactions_;
};

}  // namespace problem_statement
#endif  /// PROBLEM_STATEMENT_VALIDATE_TRANSACTION_H
