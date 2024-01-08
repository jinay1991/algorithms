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

#include "problem_statement/islands.hpp"

#include <cstdint>
#include <queue>
#include <vector>

namespace problem_statement
{

struct Location
{
    std::int32_t x;
    std::int32_t y;
};

bool IsInvalidLocation(const std::vector<std::vector<std::int32_t>>& graph, const Location& next)
{
    return ((next.x < 0) || (next.x >= graph.size()) || (next.y < 0) || (next.y >= graph[0UL].size()));
}

bool IsVisitedLocation(const std::vector<std::vector<std::int32_t>>& graph,
                       const Location& location,
                       const std::int32_t landLegend)
{
    return (graph[location.x][location.y] != landLegend);
}

// Time Complexity: O(length * breadth)
void BreadthFirstSearch(const std::vector<std::vector<std::int32_t>>& graph,
                        const Location& start,
                        const std::int32_t legend)
{
    std::vector<Location> visited{start};
    std::queue<Location> queue{start};

    while (!queue.empty())
    {
        const Location current{queue.front()};
        queue.pop();

        visited.push_back(current);
    }
}
// Time Complexity: O(length * breadth)
void DepthFirstSearch(std::vector<std::vector<std::int32_t>>& grid, int idx, int idy)
{
    if (idx < 0 || idx >= grid.size() || idy < 0 || idy >= grid[0UL].size())
        return;
    if (grid[idx][idy] != 1)
        return;

    grid[idx][idy] = 2;
    DepthFirstSearch(grid, idx + 1, idy);
    DepthFirstSearch(grid, idx - 1, idy);
    DepthFirstSearch(grid, idx, idy + 1);
    DepthFirstSearch(grid, idx, idy - 1);
}

std::int32_t GetNumberOfIslands(std::vector<std::vector<std::int32_t>>& graph, const std::int32_t landLegend)
{
    std::int32_t number_of_islands{0};

    const std::size_t length{graph.size()};
    const std::size_t breadth{graph.at(0UL).size()};

    for (std::size_t l{0UL}; l < length; ++l)
    {
        for (std::size_t b{0UL}; b < breadth; ++b)
        {
            if (graph[l][b] == landLegend)
            {
                const Location current{l, b};
                BreadthFirstSearch(graph, current, landLegend);

                // DepthFirstSearch(graph, l, b);
                ++number_of_islands;
            }
        }
    }

    return number_of_islands;
}
}  // namespace problem_statement
