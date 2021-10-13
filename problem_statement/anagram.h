///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
/// @ref https://leetcode.com/problems/group-anagrams/
///
#ifndef PROBLEM_STATEMENT_ANAGRAM_H
#define PROBLEM_STATEMENT_ANAGRAM_H

#include <string>
#include <vector>

namespace problem_statement
{

bool IsAnagram(const std::string& s1, const std::string& s2);
std::vector<std::vector<std::string>> GetAnagramGroups(const std::vector<std::string>& anagrams);

}  // namespace problem_statement
#endif  /// PROBLEM_STATEMENT_ANAGRAM_H
