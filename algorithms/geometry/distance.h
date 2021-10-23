///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_GEOMETRY_DISTANCE_H
#define ALGORITHMS_GEOMETRY_DISTANCE_H

#include <units.h>

namespace geometry
{
namespace
{
template <typename T>
constexpr units::length::meter_t ComputeSquaredDistance(const T& start, const T& end) noexcept
{
}

constexpr units::length::meter_t ComputeManhattanDistance() noexcept {}

constexpr units::length::meter_t ComputeArcLength() noexcept {}

}  // namespace
}  // namespace geometry

#endif  /// ALGORITHMS_GEOMETRY_DISTANCE_H
