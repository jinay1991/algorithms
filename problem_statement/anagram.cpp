///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/anagram.h"

#include <array>
#include <cstdint>
#include <limits>
#include <map>

namespace problem_statement
{
static constexpr std::size_t kMaxNumberOfCharacter = std::numeric_limits<std::uint8_t>::max();

bool IsAnagram(const std::string& s1, const std::string& s2)
{
    bool is_anagram = false;
    if (s1.size() != s2.size())
    {
        return is_anagram;
    }

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
    return is_anagram;
}

std::vector<std::vector<std::string>> GetAnagramGroups(const std::vector<std::string>& strs)
{
    std::vector<std::vector<std::string>> res;
    int primes[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    std::map<int, int> mp;
    int key;
    int count = 0;
    for (int i = 0; i < strs.size(); ++i)
    {
        key = 1;
        for (int j = 0; j < strs[i].size(); ++j)
        {
            key *= primes[strs[i][j] - 'a'];
        }
        if (mp.find(key) == mp.end())
        {
            mp[key] = count++;
            res.push_back(std::vector<std::string>(1, strs[i]));
        }
        else
        {
            res[mp[key]].push_back(strs[i]);
        }
    }

    return res;
}
}  // namespace problem_statement
