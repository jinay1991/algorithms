///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_GRAPH_TEST_SUPPORT_SIMPLE_GRAPH_H
#define ALGORITHMS_GRAPH_TEST_SUPPORT_SIMPLE_GRAPH_H

#include <limits>
#include <unordered_map>
#include <vector>

namespace graph
{

template <typename T>
class SimpleGraph
{
  public:
    SimpleGraph() : edges_{} {}

    void AddEdge(const T& node, const std::vector<T>& edge) { edges_[node] = edge; }

    std::vector<T> GetNeighbors(const T& id) const { return edges_[id]; }

    double GetCost(const T& from, const T& to) const { return std::numeric_limits<T>::min(); }

  private:
    std::unordered_map<T, std::vector<T>> edges_;
};

}  // namespace graph
#endif  /// ALGORITHMS_GRAPH_TEST_SUPPORT_SIMPLE_GRAPH_H
