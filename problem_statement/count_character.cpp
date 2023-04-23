///
/// @file
/// @copyright Copyright (C) 2023. MIT License.
///
#include "problem_statement/count_character.h"

#include <algorithm>
#include <iostream>

namespace problem_statement
{

std::size_t CountCharacter(const std::vector<std::string>& words, const std::string& characters) noexcept
{
    /// TODO: Implement the Algorithm -
    /// You are given an array of strings words and a string chars.
    /// A string is good if it can be formed by characters from chars (each character can only be used once).
    ///
    /// Return the sum of lengths of all good strings in words.
    ///
    /// Example 1:
    ///
    /// Input: words = ["cat","bt","hat","tree"], chars = "atach"
    /// Output: 6
    /// Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
    /// Example 2:
    ///
    /// Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
    /// Output: 10
    /// Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
    ///
    /// Constraints:
    ///
    /// 1 <= words.length <= 1000
    /// 1 <= words[i].length, chars.length <= 100
    /// words[i] and chars consist of lowercase English letters.

    std::size_t count{0};

    std::string sorted_characters{characters};
    std::sort(sorted_characters.begin(), sorted_characters.end());

    // remove duplicates
    sorted_characters.erase(std::unique(sorted_characters.begin(), sorted_characters.end()), sorted_characters.end());

    for (auto& word : words)
    {
        std::string sorted_word{word};
        std::sort(sorted_word.begin(), sorted_word.end());

        std::size_t length{0};
        for (auto& w : sorted_word)
        {
            if (sorted_characters.find(w) != std::string::npos)
            {
                ++length;
            }
        }

        // if all characters from the word is matched from sorted_characters, count it as Matched!
        if (length == sorted_word.length())
        {
            count += length;
        }
    }
    return count;
}
}  // namespace problem_statement
