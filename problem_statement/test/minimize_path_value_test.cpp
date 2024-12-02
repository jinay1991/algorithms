#include "problem_statement/minimize_path_value.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>
namespace problem_statement
{
namespace
{
using ::testing::Eq;
TEST(MinimizePathValue, GetMinimumStress_GivenTypicalGraph_ExpectMinimumStress)
{
    // Given
    const int graph{4};
    const std::vector<int> from{1, 2, 1, 4};
    const std::vector<int> to{2, 3, 4, 3};
    const std::vector<int> weight{100, 200, 10, 20};
    const int source{1};
    const int destination{3};

    // When
    const int result = getMinimumStress(graph, from, to, weight, source, destination);

    // Then
    EXPECT_THAT(result, Eq(10));
}
}  // namespace
}  // namespace problem_statement
