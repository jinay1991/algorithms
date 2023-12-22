///
/// @file
/// @copyright Copyright (C) 2023. MIT License.
///

// --------------------------------------------------------------------------------------------------------------------
// Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water), return the number of islands.
//
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may
// assume all four edges of the grid are all surrounded by water.
//
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
//
// Input: grid = [
//   ["1","1","0","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 2
// --------------------------------------------------------------------------------------------------------------------
#ifndef PROBLEM_STATEMENT_ISLANDS_HPP
#define PROBLEM_STATEMENT_ISLANDS_HPP

#include <cstdint>
#include <vector>

namespace problem_statement
{
int GetIslandFromGraph(const std::vector<std::vector<std::int32_t>>& graph) {}

}  // namespace problem_statement

#endif  /// PROBLEM_STATEMENT_ISLANDS_HPP
