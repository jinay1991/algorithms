///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef PROBLEM_STATEMENT_IS_PRIME_H
#define PROBLEM_STATEMENT_IS_PRIME_H

#include <cmath>
#include <cstdint>
#include <vector>

namespace problem_statement
{

constexpr bool IsPrime(const std::int32_t value) noexcept
{
    if (value <= 3)
    {
        return true;
    }
    for (auto i = 3; i < std::sqrt(value); i++)
    {
        if (value % i == 0)
        {
            return false;
        }
    }
    return true;
}

std::vector<std::int32_t> GetPrimeNumbersBeforeN(const std::int32_t n) noexcept
{
    std::vector<std::int32_t> result;
    /// @todo: Implement most efficient method to find all the prime numbers before n.
    return result;
}

}  // namespace problem_statement

#endif  /// PROBLEM_STATEMENT_IS_PRIME_H
