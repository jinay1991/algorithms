///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/find_max_rides.h"

#include <algorithm>
#include <iostream>
#include <vector>

namespace problem_statement
{

int find_max_rides(std::vector<std::vector<int>> requests)
{
    int time_elapsed = 0;
    int max_ride = 0;
    std::sort(requests.begin(),
              requests.end(),
              [](const auto& ride_1, const auto& ride_2) -> bool
              { return (std::abs(ride_1[0U] - ride_1[1U]) < std::abs(ride_1[0U] - ride_1[1U])); });

    for (auto& ride : requests)
    {
        std::cout << ride[0] << ", " << ride[1] << std::endl;
    }

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
