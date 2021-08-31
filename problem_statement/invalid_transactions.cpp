///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/invalid_transactions.h"

#include <algorithm>
#include <cstdlib>
#include <sstream>

namespace problem_statement
{
namespace
{

constexpr std::chrono::minutes absdiff(const std::chrono::minutes& current,
                                       const std::chrono::minutes& previous) noexcept
{
    return ((current > previous) ? (current - previous) : (previous - current));
}

}  // namespace
using namespace std::chrono_literals;

static constexpr std::uint32_t kMaxTransactionAmount{1000U};

InvalidTransactions::InvalidTransactions() : previous_transactions_{} {}

std::vector<std::string> InvalidTransactions::GetInvalidTransactions(
    const std::vector<std::string>& transactions) noexcept
{
    std::vector<std::string> invalid_transactions;

    for (const auto& transaction : transactions)
    {
        const auto parsed_transaction = ParseTransaction(transaction);
        if (!IsTransactionAmountInvalid(parsed_transaction))
        {
            previous_transactions_.push_back(parsed_transaction);
        }
    }

    std::copy_if(transactions.cbegin(),
                 transactions.cend(),
                 std::back_inserter(invalid_transactions),
                 [this](const auto& transaction) { return IsTransactionInvalid(transaction); });

    return invalid_transactions;
}

Transaction InvalidTransactions::ParseTransaction(const std::string& transaction) const noexcept
{
    Transaction result;

    std::stringstream stream{transaction};
    const char delimiter{','};
    std::string time_min_str;
    std::string amount_str;

    std::getline(stream, result.name, delimiter);
    std::getline(stream, time_min_str, delimiter);
    std::getline(stream, amount_str, delimiter);
    std::getline(stream, result.city, delimiter);

    result.time = std::chrono::minutes{std::stoi(time_min_str)};
    result.amount = static_cast<std::uint32_t>(std::stoi(amount_str));

    return result;
}

bool InvalidTransactions::IsTransactionAmountInvalid(const Transaction& parsed_transaction) const noexcept
{
    return (parsed_transaction.amount > kMaxTransactionAmount);
}

bool InvalidTransactions::IsTransactionRepeated(const Transaction& parsed_transaction) const noexcept
{
    const auto it = std::find_if(previous_transactions_.cbegin(),
                                 previous_transactions_.cend(),
                                 [&current_transaction = parsed_transaction](const auto& previous_transaction)
                                 {
                                     return ((absdiff(current_transaction.time, previous_transaction.time) <= 60min) &&
                                             (current_transaction.name == previous_transaction.name) &&
                                             (current_transaction.city != previous_transaction.city));
                                 });
    return (it != previous_transactions_.cend());
}

bool InvalidTransactions::IsTransactionInvalid(const std::string& transaction) const noexcept
{
    const auto parsed_transaction = ParseTransaction(transaction);
    return (IsTransactionAmountInvalid(parsed_transaction) || IsTransactionRepeated(parsed_transaction));
}

}  // namespace problem_statement
