///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_GRAPH_TEST_SUPPORT_SQUARE_GRID_H
#define ALGORITHMS_GRAPH_TEST_SUPPORT_SQUARE_GRID_H

#include "algorithms/graph/test/support/grid_location.h"

#include <units.h>

#include <array>
#include <unordered_set>
#include <vector>

namespace graph
{

class SquareGrid
{
  public:
    static constexpr std::size_t kMaxDirection = 4U;

    using Directions = std::array<GridLocation, kMaxDirection>;
    using Neighbors = std::vector<GridLocation>;
    using Blocks = std::unordered_set<GridLocation>;

    explicit SquareGrid(const units::length::meter_t width, const units::length::meter_t height);

    void AddBlock(const GridLocation& start, const GridLocation& end);

    Neighbors GetNeighbors(GridLocation id) const;

    units::length::meter_t GetHeight() const;
    units::length::meter_t GetWidth() const;

    inline bool IsInside(const GridLocation& id) const noexcept;

    inline bool IsBlocked(GridLocation id) const;

  private:
    units::length::meter_t width_;
    units::length::meter_t height_;

    Blocks blocks_;

    const Directions directions_;
};

}  // namespace graph
#endif  /// ALGORITHMS_GRAPH_TEST_SUPPORT_SQUARE_GRID_H
