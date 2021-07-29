///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/anagram.h"

#include <array>
#include <cstdint>
#include <limits>

namespace problem_statement
{
static constexpr std::size_t kMaxNumberOfCharacter = std::numeric_limits<std::uint8_t>::max();

bool IsAnagram(const std::string& s1, const std::string& s2)
{
    bool is_anagram = false;
    if (s1.size() == s2.size())
    {
        std::array<std::int32_t, kMaxNumberOfCharacter> lookup1{};
        std::array<std::int32_t, kMaxNumberOfCharacter> lookup2{};

        for (const auto& ch : s1)
        {
            const std::size_t position = static_cast<std::size_t>(ch);
            lookup1.at(position) += 1;
        }

        for (const auto& ch : s2)
        {
            const std::size_t position = static_cast<std::size_t>(ch);
            lookup2.at(position) += 1;
        }

        is_anagram = (lookup1 == lookup2);
    }
    return is_anagram;
}
}  // namespace problem_statement
