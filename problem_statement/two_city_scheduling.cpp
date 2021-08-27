///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/two_city_scheduling.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

namespace problem_statement
{

std::int32_t TwoCityScheduling::ComputeMinimalCost(const std::vector<std::vector<std::int32_t>>& costs)
{
    const auto persons_per_city = costs.size() / 2UL;

    auto costs_heap = costs;

    std::sort(costs_heap.begin(),
              costs_heap.end(),
              [](const auto& cost1, const auto& cost2) { return ((cost1[1] - cost1[0]) > (cost2[1] - cost2[0])); });

    std::int32_t minimal_cost = 0;
    for (auto i = 0UL; i < persons_per_city; ++i)
    {
        minimal_cost += costs_heap[i][0];
    }

    for (auto i = persons_per_city; i < costs.size(); ++i)
    {
        minimal_cost += costs_heap[i][1];
    }

    return minimal_cost;
}

}  // namespace problem_statement
