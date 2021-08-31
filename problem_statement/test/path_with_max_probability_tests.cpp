///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/path_with_max_probability.h"

#include <gtest/gtest.h>

namespace problem_statement
{
namespace
{

class PathWithMaxProbabilityFixture : public ::testing::Test
{
  public:
    PathWithMaxProbabilityFixture() : unit_{} {}

  protected:
    PathWithMaxProbability unit_;
};

template <typename T>
class PathWithMaxProbabilityFixtureT : public PathWithMaxProbabilityFixture, public ::testing::WithParamInterface<T>
{
};

struct TestInputParam
{
    // Given
    std::int32_t n;
    std::vector<std::vector<std::int32_t>> edges;
    std::vector<double> success_probability;
    std::int32_t start;
    std::int32_t end;

    // Then
    double max_probability;
};

using PathWithMaxProbabilityFixture_WithInputs = PathWithMaxProbabilityFixtureT<TestInputParam>;

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    PathWithMaxProbability,
    PathWithMaxProbabilityFixture_WithInputs,
    ::testing::Values(
        ///             n,          edges         ,       success_probability,        start,      end,        (expected) max_probability
        TestInputParam{ 3, {{0,1}, {1, 2}, {0, 2}},          {0.5, 0.5, 0.2} ,            0,        2,                  0.25            }
));
// clang-format on

TEST_P(PathWithMaxProbabilityFixture_WithInputs, GivenTypicalInputs_ExpectMaxProbability)
{
    // Given
    const auto param = GetParam();

    // When
    const auto max_probability =
        unit_.GetMaxProbability(param.n, param.edges, param.success_probability, param.start, param.end);

    // Then
    EXPECT_EQ(max_probability, param.max_probability);
}
}  // namespace
}  // namespace problem_statement
