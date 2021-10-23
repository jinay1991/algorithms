///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/tallest_billboard.h"

#include <gtest/gtest.h>

namespace problem_statement
{
namespace
{
class TallestBillboardFixture : public ::testing::Test
{
  protected:
    TallestBillboard unit_{};
};

template <typename T>
class TallestBillboardFixtureT : public TallestBillboardFixture, public ::testing::WithParamInterface<T>
{
};

struct TestRodsParam
{
    // Given
    std::vector<std::int32_t> rods;

    // Then
    std::int32_t tallest_billboard;
};

using TallestBillboardFixture_WithRods = TallestBillboardFixtureT<TestRodsParam>;

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    TallestBillboard,
    TallestBillboardFixture_WithRods,
    ::testing::Values(
        ///             rods            , (expected) tallest_billboard
        TestRodsParam{{1,2,3,6}         ,                           6},
        TestRodsParam{{1,2,3,4,5,6}     ,                          10},
        TestRodsParam{{1,2}             ,                           0}
));
// clang-format on

TEST_P(TallestBillboardFixture_WithRods, GetTallestBillboard_GivenTypicalRods_ExpectTallestBillboard)
{
    // Given
    const auto param = GetParam();

    // When
    const auto tallest_billboard = unit_.GetTallestBillboard(param.rods);

    // Then
    EXPECT_EQ(tallest_billboard, param.tallest_billboard);
}

}  // namespace
}  // namespace problem_statement
