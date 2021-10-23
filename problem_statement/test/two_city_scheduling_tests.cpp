///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/two_city_scheduling.h"

#include <gtest/gtest.h>

namespace problem_statement
{
namespace
{
class TwoCitySchedulingFixture : public ::testing::Test
{
  public:
    TwoCitySchedulingFixture() : unit_{} {}

  protected:
    TwoCityScheduling unit_;
};

template <typename T>
class TwoCitySchedulingFixtureT : public TwoCitySchedulingFixture, public ::testing::WithParamInterface<T>
{
};

struct TestCostsParam
{
    // Given
    std::vector<std::vector<std::int32_t>> costs;

    // Then
    std::int32_t minimal_cost;
};

using TwoCitySchedulingFixture_WithCosts = TwoCitySchedulingFixtureT<TestCostsParam>;

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    TwoCityScheduling,
    TwoCitySchedulingFixture_WithCosts,
    ::testing::Values(
        //                      costs                                                                 , (expected) minimal_cost
        TestCostsParam{{{10,20},{30,200},{400,50},{30,20}}                                            ,                    110},
        TestCostsParam{{{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}}                   ,                   1859},
        TestCostsParam{{{515,563},{451,713},{537,709},{343,819},{855,779},{457,60},{650,359},{631,42}},                   3086}
));
// clang-format on

TEST_P(TwoCitySchedulingFixture_WithCosts, ComputeMinimalCost_GivenTypicalCosts_ExpectComputedMinimalCost)
{
    // Given
    const auto param = GetParam();

    // When
    const auto minimal_cost = unit_.ComputeMinimalCost(param.costs);

    // Then
    EXPECT_EQ(minimal_cost, param.minimal_cost);
}

}  // namespace
}  // namespace problem_statement
