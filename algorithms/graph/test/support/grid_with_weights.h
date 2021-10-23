///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_GRAPH_TEST_SUPPORT_GRID_WITH_WEIGHTS_H
#define ALGORITHMS_GRAPH_TEST_SUPPORT_GRID_WITH_WEIGHTS_H

#include "algorithms/graph/test/support/grid_location.h"
#include "algorithms/graph/test/support/square_grid.h"

#include <units.h>

#include <array>
#include <unordered_set>
#include <vector>

namespace graph
{

class GridWithWeights : public SquareGrid
{
  public:
    explicit GridWithWeights(const units::length::meter_t width, const units::length::meter_t height);
    void AddForest(const GridLocation& location);
    double GetCost(const GridLocation& from, const GridLocation& to) const;

  private:
    std::unordered_set<GridLocation> forests_;
};

}  // namespace graph
#endif  /// ALGORITHMS_GRAPH_TEST_SUPPORT_GRID_WITH_WEIGHTS_H
