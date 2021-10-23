///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/graph/test/support/grid_location.h"

namespace graph
{

bool operator==(const GridLocation& lhs, const GridLocation& rhs) noexcept
{
    return ((lhs.x == rhs.x) && (lhs.y == rhs.y));
}

bool operator!=(const GridLocation& lhs, const GridLocation& rhs) noexcept
{
    return !(lhs == rhs);
}

bool operator<(const GridLocation& lhs, const GridLocation& rhs) noexcept
{
    return ((lhs.x < rhs.x) && (lhs.y < rhs.y));
}

std::ostream& operator<<(std::ostream& out, const GridLocation& location) noexcept
{
    out << '(' << location.x << ',' << location.y << ')';
    return out;
}
}  // namespace graph
