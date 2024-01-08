///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_GRAPH_GRAPH_H
#define ALGORITHMS_GRAPH_GRAPH_H

#include <bitset>
#include <list>
#include <memory>
#include <queue>

namespace graph
{
template <typename T, std::size_t kMaxNumberOfNodes>
class Graph
{
  public:
    using value_type = T;
    using Node = value_type;
    using Path = std::list<Node>;

    constexpr Graph() : nodes_{} {}

    constexpr void AddEdge(const Node& start, const Node& end) { nodes_.at(start).push_back(end); }

    constexpr bool IsRouteExists(const Node& start, const Node& end) const
    {
        bool exists = false;
        std::bitset<kMaxNumberOfNodes> visited{};
        std::queue<Node> queue{};
        queue.push(start);
        visited[start] = true;

        while (!queue.empty())
        {
            const auto current = queue.front();
            queue.pop();

            visited[current] = true;

            if (current == end)
            {
                exists = true;
                break;
            }

            for (const auto& neighbour : GetNeighbours(current))
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    queue.push(neighbour);
                }
            }
        }
        return exists;
    }

  private:
    constexpr const Path& GetNeighbours(const Node& current) const { return nodes_.at(current); }

    std::array<Path, kMaxNumberOfNodes> nodes_;
};
}  // namespace graph

#endif  /// ALGORITHMS_GRAPH_GRAPH_H
