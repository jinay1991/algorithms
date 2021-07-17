///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_GRAPH_TEST_SUPPORT_SIMPLE_GRAPH_BUILDER_H
#define ALGORITHMS_GRAPH_TEST_SUPPORT_SIMPLE_GRAPH_BUILDER_H

#include "algorithms/graph/test/support/simple_graph.h"

#include <vector>

namespace graph
{

template <typename T>
class SimpleGraphBuilder
{
  public:
    SimpleGraphBuilder() : graph_{} {}

    SimpleGraphBuilder& WithEdge(const T& node, const std::vector<T>& edge)
    {
        graph_.AddEdge(node, edge);
        return *this;
    }

    const SimpleGraph<T>& Build() const { return graph_; }

  private:
    SimpleGraph<T> graph_;
};

}  // namespace graph
#endif  /// ALGORITHMS_GRAPH_TEST_SUPPORT_SIMPLE_GRAPH_BUILDER_H
