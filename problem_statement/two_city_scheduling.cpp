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

namespace
{
inline std::int32_t ComputeProfitForCityA(const std::vector<std::int32_t>& costs) noexcept
{
    const auto city_a_cost = costs[0];
    const auto city_b_cost = costs[1];
    return (city_b_cost - city_a_cost);
}
}  // namespace

std::int32_t TwoCityScheduling::ComputeMinimalCost(const std::vector<std::vector<std::int32_t>>& costs)
{
    const auto persons_per_city = costs.size() / 2UL;
    auto sorted_costs = costs;

    std::sort(sorted_costs.begin(),
              sorted_costs.end(),
              [this](const auto& cost1, const auto& cost2)
              { return (ComputeProfitForCityA(cost1) > ComputeProfitForCityA(cost2)); });

    std::int32_t minimal_cost = 0;

    for (auto i = 0UL; i < persons_per_city; ++i)
    {
        const auto city_a_cost = sorted_costs[i][0];
        const auto city_b_cost = sorted_costs[persons_per_city + i][1];
        minimal_cost += city_a_cost + city_b_cost;
    }

    return minimal_cost;
}

}  // namespace problem_statement
