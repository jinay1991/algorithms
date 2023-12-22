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

namespace problem_statement
{
struct Location
{
    std::size_t x;
    std::size_t y;
};

int GetIslandFromGraph(const std::vector<std::vector<std::int32_t>>& graph,
                       const std::int32_t landLegend,
                       const std::int32_t waterLegend)
{
    const std::size_t length{graph.size()};
    const std::size_t breadth{graph.at(0UL).size()};

    std::queue<Location> queue;
    Location start{0UL, 0UL};
    queue.push(start);

    while (!queue.empty())
    {
        Location current{queue.front()};
        queue.pop();

        if (graph.at(current.x).at(current.y) == waterLegend)
        {
            break;
        }

        static constexpr std::vector<Location> directions{Location{-1, -1},
                                                          Location{0, -1},
                                                          Location{1, -1},
                                                          Location{-1, 0},
                                                          Location{1, 0},
                                                          Location{-1, 1},
                                                          Location{0, 1},
                                                          Location{1, 1}};
        for (auto& dir : directions)
        {
            const Location next{current.x + dir.x, current.y + dir.y};
            if (next.x > )
            {
            }
        }
    }
}
}  // namespace problem_statement
