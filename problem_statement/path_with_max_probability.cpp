///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/path_with_max_probability.h"

#include <queue>

namespace problem_statement
{
namespace
{
template <typename NodeType, typename CostType>
class GraphBuilder
{
  public:
    using Graph = std::map<NodeType, std::pair<CostType, NodeType>>;

    constexpr GraphBuilder() : graph_{} {}

    constexpr void AddEdges(const std::vector<NodeType>& edges, const std::vector<CostType>& costs)
    {
        if (edges.size() != costs.size())
        {
            return;
        }

        for (auto i = 0UL; i < edges.size(); ++i)
        {
            const auto edge = edges.at(i);
            const auto cost = costs.at(i);
            AddEdge(edge.at(0UL), edge.at(1UL), cost);
        }
    }

    constexpr void AddEdge(const NodeType& start, const NodeType& end, const CostType& cost)
    {
        graph_[start].push_back(cost, end);
        graph_[end].push_back(cost, start);
    }

    constexpr const Graph& Build() const { return graph_; }

  private:
    Graph graph_;
};
}  // namespace

double PathWithMaxProbability::GetMaxProbability(const std::int32_t n,
                                                 const std::vector<std::vector<std::int32_t>>& edges,
                                                 const std::vector<double>& success_probability,
                                                 const std::int32_t start,
                                                 const std::int32_t end)
{
    // const auto graph = GraphBuilder<std::int32_t, double>().AddEdges(edges, success_probability).Build();

    // std::vector<bool> visited(n);
    // std::priority_queue<std::pair<double, std::int32_t>> priority_queue;
    // priority_queue.emplace(graph[start]);

    // while (!priority_queue.empty())
    // {
    //     const auto node_cost_pair = priority_queue.top();
    //     priority_queue.pop();

    //     const auto node = node_cost_pair.second;
    //     // const auto cost = node_cost_pair.first;
    //     if (visited.at(node))
    //     {
    //         continue;
    //     }
    //     visited.at(node) = true;

    //     for (auto& next_node_cost_pair : graph[node]) {
    //         const auto next_node = next_node_cost_pair.second;
    //         const auto next_cost = next_node_cost_pair.first;

    //         if (success_probability[next_node] > success_probability[node] )
    //     }
    // }
    return 0.0;
}

}  // namespace problem_statement
