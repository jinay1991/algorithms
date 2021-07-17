///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_GRAPH_TEST_SUPPORT_SQUARE_GRID_BUILDER_H
#define ALGORITHMS_GRAPH_TEST_SUPPORT_SQUARE_GRID_BUILDER_H

#include "algorithms/graph/test/support/grid_location.h"
#include "algorithms/graph/test/support/square_grid.h"

#include <units.h>

namespace graph
{

class SquareGridBuilder
{
  public:
    explicit SquareGridBuilder(const units::length::meter_t width, const units::length::meter_t height);
    SquareGridBuilder& WithBlock(const GridLocation& start, const GridLocation& end);
    const SquareGrid& Build() const;

  private:
    SquareGrid grid_;
};

}  // namespace graph
#endif  /// ALGORITHMS_GRAPH_TEST_SUPPORT_SQUARE_GRID_BUILDER_H
