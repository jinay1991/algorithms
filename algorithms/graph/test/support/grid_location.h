///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_GRAPH_TEST_SUPPORT_GRID_LOCATION_H
#define ALGORITHMS_GRAPH_TEST_SUPPORT_GRID_LOCATION_H

#include <units.h>

#include <functional>
#include <ostream>
#include <string>

namespace graph
{

struct GridLocation
{
    units::length::meter_t x;
    units::length::meter_t y;
};

bool operator==(const GridLocation& lhs, const GridLocation& rhs) noexcept;
bool operator!=(const GridLocation& lhs, const GridLocation& rhs) noexcept;
bool operator<(const GridLocation& lhs, const GridLocation& rhs) noexcept;
std::ostream& operator<<(std::ostream& out, const GridLocation& location) noexcept;

}  // namespace graph

namespace std
{
/* implement hash function so we can put GridLocation into an unordered_set */
template <>
struct hash<graph::GridLocation>
{
    typedef graph::GridLocation argument_type;
    typedef std::size_t result_type;
    std::size_t operator()(const graph::GridLocation& id) const noexcept
    {
        return (std::hash<std::int32_t>()(id.x.to<std::int32_t>() ^ (id.y.to<std::int32_t>() << 4)));
    }
};
}  // namespace std
#endif  /// ALGORITHMS_GRAPH_TEST_SUPPORT_GRID_LOCATION_H
