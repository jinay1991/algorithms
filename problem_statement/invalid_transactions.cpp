///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/invalid_transactions.h"

#include <algorithm>
#include <sstream>

namespace problem_statement
{

using namespace std::chrono_literals;

static constexpr std::uint32_t kMaxTransactionAmount{1000U};

InvalidTransactions::InvalidTransactions() : previous_transaction_{} {}

std::vector<std::string> InvalidTransactions::GetInvalidTransactions(
    const std::vector<std::string>& transactions) noexcept
{
    std::vector<std::string> invalid_transactions;

    for (auto it = transactions.begin(); it != transactions.end(); ++it)
    {
        const auto transaction = ParseTransaction(*it);

        if (transaction.amount > kMaxTransactionAmount)
        {
            invalid_transactions.push_back(*it);
        }
        else
        {
            if (HasPreviousTransaction() && IsTransactionAllowed(transaction))
            {
                invalid_transactions.push_back(*(it - 1));
                invalid_transactions.push_back(*it);
            }
            else
            {
                previous_transaction_ = transaction;
            }
        }
    }

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
    result.amount = std::stoi(amount_str);

    return result;
}

bool InvalidTransactions::IsTransactionAmountValid(const Transaction& transaction) const noexcept
{
    return (transaction.amount <= kMaxTransactionAmount);
}

bool InvalidTransactions::IsTransactionAllowed(const Transaction& transaction) const noexcept
{
    return ((transaction.time - previous_transaction_.time <= 60min) &&
            (transaction.name == previous_transaction_.name) && (transaction.city != previous_transaction_.city));
}

bool InvalidTransactions::HasPreviousTransaction() const noexcept
{
    return ((previous_transaction_.time != 0min) && (!previous_transaction_.name.empty()) &&
            (!previous_transaction_.city.empty()) && (previous_transaction_.amount != 0U));
}

}  // namespace problem_statement
