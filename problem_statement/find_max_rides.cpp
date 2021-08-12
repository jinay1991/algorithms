///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/find_max_rides.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

namespace problem_statement
{

int find_max_rides(std::vector<std::vector<int>> requests)
{
    int time_elapsed = 0;
    int max_ride = 0;

    std::make_heap(requests.begin(),
                   requests.end(),
                   [](const auto& ride_1, const auto& ride_2) -> bool
                   { return (std::floor(ride_1[1UL] / ride_1[0UL]) < std::floor(ride_2[1UL] / ride_2[1UL])); });

    for (const auto& ride : requests)
    {
        const auto trip_duration = ride[0];
        const auto deadline = ride[1];
        if (time_elapsed + trip_duration > deadline)
        {
            continue;
        }
        else
        {
            time_elapsed += trip_duration;
            max_ride++;
        }
    }
    return max_ride;
}

}  // namespace problem_statement
