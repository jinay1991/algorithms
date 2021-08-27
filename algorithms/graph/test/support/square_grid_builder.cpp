///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/graph/test/support/square_grid_builder.h"

namespace graph
{

SquareGridBuilder::SquareGridBuilder(const units::length::meter_t width, const units::length::meter_t height)
    : grid_{width, height}
{
}

SquareGridBuilder& SquareGridBuilder::WithBlock(const GridLocation& start, const GridLocation& end)
{
    grid_.AddBlock(start, end);
    return *this;
}

const SquareGrid& SquareGridBuilder::Build() const
{
    return grid_;
}

}  // namespace graph
