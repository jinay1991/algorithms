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
        std::array<std::int32_t, kMaxNumberOfCharacter> lookup{};

        for (auto idx = 0UL; idx < s1.size(); ++idx)
        {
            const auto position1 = static_cast<std::size_t>(s1.at(idx));
            const auto position2 = static_cast<std::size_t>(s2.at(idx));
            lookup.at(position1)++;
            lookup.at(position2)--;
        }

        is_anagram = true;
        for (const auto& count : lookup)
        {
            if (count != 0)
            {
                is_anagram = false;
                break;
            }
        }
    }
    return is_anagram;
}
}  // namespace problem_statement
