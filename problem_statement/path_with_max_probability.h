///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
/// @ref https://leetcode.com/problems/path-with-maximum-probability/
///
#ifndef PROBLEM_STATEMENT_PATH_WITH_MAX_PROBABILITY_H
#define PROBLEM_STATEMENT_PATH_WITH_MAX_PROBABILITY_H

#include <cstdint>
#include <map>
#include <queue>
#include <utility>
#include <vector>

namespace problem_statement
{

class PathWithMaxProbability
{
  public:
    double GetMaxProbability(const std::int32_t n,
                             const std::vector<std::vector<std::int32_t>>& edges,
                             const std::vector<double>& success_probability,
                             const std::int32_t start,
                             const std::int32_t end);
};

}  // namespace problem_statement

#endif  /// PROBLEM_STATEMENT_PATH_WITH_MAX_PROBABILITY_H
