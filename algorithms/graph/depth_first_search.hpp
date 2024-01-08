///
/// @file
/// @copyright Copyright (C) 2024. MIT License.
///
#ifndef ALGORITHMS_GRAPH_DEPTH_FIRST_SEARCH_HPP
#define ALGORITHMS_GRAPH_DEPTH_FIRST_SEARCH_HPP

#include <algorithm>
#include <stack>
#include <unordered_map>
#include <vector>

namespace graph
{
template <typename Graph, typename Location>
class DepthFirstSearch
{
  public:
    ///
    /// @brief Shortest Path (List of Locations)
    ///
    using ShortestPath = std::vector<Location>;

    constexpr explicit DepthFirstSearch(const Graph& graph) : graph_{graph}, visited_{}, shortest_path_{}
    {
        static_assert(std::is_pod<Location>::value, "Location must be plain type.");
    }

    ///
    /// @brief Search Shortest Path between Start and End Locations using A* and reconstruct shortest path.
    ///
    /// @param start [in] Start Location
    /// @param end [in] End Location
    ///
    void SearchShortestPath(const Location& start, const Location& end) noexcept
    {
        DetermineShortestPath(start, end);
        ReconstructShortestPath(start, end);
    }

    ///
    /// @brief Provide resultant shortest path (List of Locations)
    ///
    /// @return shortest path (list of Locations)
    ///
    constexpr const ShortestPath& GetShortestPath() const noexcept { return shortest_path_; }

  private:
    ///
    /// @brief Determine Shortest Path between start and end Locations on Graph using Breadth First Search algorithm.
    ///
    /// @param start [in] Start Location on Graph/Grid
    /// @param end [in] End Location on Graph/Grid
    ///
    constexpr void DetermineShortestPath(const Location& start, const Location& end)
    {
        std::stack<Location> stack;
        stack.push(start);

        visited_[start] = start;

        while (!stack.empty())
        {
            Location current = stack.top();
            stack.pop();

            if (current == end)
            {
                break;
            }

            for (Location next : graph_.GetNeighbours(current))
            {
                if (visited_.find(next) == visited_.end())
                {
                    stack.push(next);
                    visited_[next] = current;
                }
            }
        }
    }

    ///
    /// @brief Reconstructs the Path from already analyzed Graph/Grid using Breadth First Search by preparing the list
    /// of Locations which can be joined together to represent the Shortest Path.
    ///
    /// @param start [in] Start Location on Graph/Grid
    /// @param end [in] End Location on Graph/Grid
    ///
    constexpr void ReconstructShortestPath(const Location& start, const Location& end)
    {
        shortest_path_.clear();
        Location current = end;
        while (current != start)
        {
            shortest_path_.push_back(current);
            current = visited_[current];
        }
        shortest_path_.push_back(start);
        std::reverse(shortest_path_.begin(), shortest_path_.end());
    }

    ///
    /// @brief Instance of Graph/Grid.
    /// @warning Graph must have method GetNeighbours
    ///
    const Graph& graph_;

    ///
    /// @brief Location Map for all the visited nodes/cells on Graph/Grid with it's relation to previous node/cell.
    ///
    std::unordered_map<Location, Location> visited_;

    ///
    /// @brief Shortest Path found using A* in form of List of Locations.
    ///
    ShortestPath shortest_path_;
};
}  // namespace graph

#endif  /// ALGORITHMS_GRAPH_DEPTH_FIRST_SEARCH_HPP
