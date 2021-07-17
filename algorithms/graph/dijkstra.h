///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_GRAPH_DIJKSTRA_H
#define ALGORITHMS_GRAPH_DIJKSTRA_H

#include "algorithms/graph/astar.h"

#include <limits>

namespace graph
{

///
/// @class Dijkstra
/// @brief Provide Dijkstra based shortest path search functionality for given Graph.
/// @note Dijkstra is a special case of A* with Heuristic Cost always Zero. Hence inherit all the properties of A* and
/// overriden the Heuristic Function to always result into Zero.
///
/// @tparam Graph [in] Graph Type to look in for finding shorest path using A*.
/// @tparam Location [in] Location Type for each node/cell in Graph represented in cartesian coordinate systems.
/// @tparam Cost [in] Cost Type for computing Cost for given node/cell while computing Shortest Path.
///
template <typename Graph, typename Location, typename Cost = double>
class Dijkstra : public AStar<Graph, Location, Cost>
{
  public:
    ///
    /// @brief Constructor for Dijkstra
    ///
    /// @param graph [in] Instance to the Graph/Grid
    ///
    constexpr explicit Dijkstra(const Graph& graph) : AStar<Graph, Location, Cost>{graph} {}

  protected:
    ///
    /// @brief Provide Heuristic Cost for given Locations (from & to) for Dijkstra.
    /// @note Heuristic Cost = 0 for Dijkstra.
    ///
    /// @param from [in] Location from for calculating Heuristic Cost
    /// @param to [in] Location to for calculating Heuristic Cost
    ///
    /// @return Computed Cost for given Locations.
    ///
    constexpr Cost GetHeuristicCost(const Location& /* from */, const Location& /* to */) const override
    {
        return std::numeric_limits<Cost>::min();
    }
};
}  // namespace graph
#endif  /// ALGORITHMS_GRAPH_DIJKSTRA_H
