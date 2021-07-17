///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_GRAPH_TEST_SUPPORT_GRID_WITH_WEIGHTS_BUILDER_H
#define ALGORITHMS_GRAPH_TEST_SUPPORT_GRID_WITH_WEIGHTS_BUILDER_H

#include "algorithms/graph/test/support/grid_location.h"
#include "algorithms/graph/test/support/grid_with_weights.h"

#include <units.h>

#include <initializer_list>

namespace graph
{

class GridWithWeightsBuilder
{
  public:
    explicit GridWithWeightsBuilder(const units::length::meter_t width, const units::length::meter_t height);
    GridWithWeightsBuilder& WithForest(const GridLocation& location);
    GridWithWeightsBuilder& WithForestList(const std::initializer_list<GridLocation>& location_list);
    GridWithWeightsBuilder& WithBlock(const GridLocation& start, const GridLocation& end);
    const GridWithWeights& Build() const;

  private:
    GridWithWeights grid_;
};

}  // namespace graph
#endif  /// ALGORITHMS_GRAPH_TEST_SUPPORT_GRID_WITH_WEIGHTS_BUILDER_H
