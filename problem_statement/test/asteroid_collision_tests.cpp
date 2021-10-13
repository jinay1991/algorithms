///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/asteroid_collision.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

namespace problem_statement
{
namespace
{

struct TestAsteroidParam
{
    // Given
    std::vector<std::int32_t> asteroids;

    // Then
    std::vector<std::int32_t> resultant_asteroids;
};

class AsteroidCollisionFixture : public ::testing::TestWithParam<TestAsteroidParam>
{
};
// clang-format off
INSTANTIATE_TEST_SUITE_P(
    AsteroidCollision,
    AsteroidCollisionFixture,
    ::testing::Values(
        //                      asteroids, (expected) resultant_asteroids
        TestAsteroidParam{    {5, 10, -5},            {5, 10}            },
        TestAsteroidParam{ {5, 10, 2, -5},            {5, 10}            },
        TestAsteroidParam{        {8, -8},                 {}            },
        TestAsteroidParam{ {-1, -2, 1, 2},     {-1, -2, 1, 2}            },
        TestAsteroidParam{   {5, 10, -15},              {-15}            }
));
// clang-format on

TEST_P(AsteroidCollisionFixture, AsteroidCollision_GivenTypicalAsteroid_ExpectResultantAsteroids)
{
    // Given
    const auto param = GetParam();

    // When
    const auto result = AsteroidCollision(param.asteroids);

    // Then
    EXPECT_EQ(result, param.resultant_asteroids);
}
}  // namespace
}  // namespace problem_statement
