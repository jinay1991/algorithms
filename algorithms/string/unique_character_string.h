///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_STRING_UNIQUE_CHARACTER_STRING_H
#define ALGORITHMS_STRING_UNIQUE_CHARACTER_STRING_H

#include <bitset>
#include <cstdint>
#include <iostream>
#include <limits>
#include <string>

namespace string
{

bool IsUniqueCharacterString(const std::string& data) noexcept
{
    constexpr std::size_t kMaxNumberOfCharacters = static_cast<std::size_t>(std::numeric_limits<std::uint8_t>::max());
    std::bitset<kMaxNumberOfCharacters> hash_table{};
    hash_table.reset();

    bool result = true;
    for (const std::uint8_t value : data)
    {
        if (hash_table[value])
        {
            result = false;
            break;
        }
        hash_table.set(value);
    }

    return result;
}

}  // namespace string

#endif  /// ALGORITHMS_STRING_UNIQUE_CHARACTER_STRING_H
