///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "argoai/find_max_rides.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <vector>

namespace argoai
{
namespace
{
class FindMaxRidesFixture : public ::testing::Test
{
  protected:
    inline std::vector<std::vector<int>> GenerateTestRequests() const
    {
        std::vector<std::vector<int>> requests;
        {
            std::vector<int> ride;
            ride.push_back(2);
            ride.push_back(7);
            requests.push_back(ride);
        }
        {
            std::vector<int> ride;
            ride.push_back(5);
            ride.push_back(5);
            requests.push_back(ride);
        }
        return requests;
    }
};

/**
   Test case 4 requests:
       2 7
       5 5
*/
TEST_F(FindMaxRidesFixture, GivenTypicalRideRequests_ExpectMaxRides)
{
    // Given
    const auto requests = GenerateTestRequests();

    // When
    const auto max_rides = find_max_rides(requests);

    // Then
    EXPECT_EQ(max_rides, 2U);
}
}  // namespace
}  // namespace argoai