///
/// @file
/// @copyright Copyright (C) 2024. MIT License.
///
#include "problem_statement/islands.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace problem_statement
{
namespace
{
TEST(NumberOfIslands, GivenTypicalGraph_ExpectOneNumberOfIslands)
{
    // Given
    std::vector<std::vector<std::int32_t>> graph{{{1, 1, 1, 1, 0}, {1, 1, 0, 1, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 0, 0}}};

    // When
    const std::int32_t number_of_islands{GetNumberOfIslands(graph)};

    // Then
    EXPECT_EQ(1, number_of_islands);
}

TEST(NumberOfIslands, GivenTypicalGraph_ExpectTwoNumberOfIslands)
{
    // Given
    std::vector<std::vector<std::int32_t>> graph{{{1, 1, 0, 1, 0}, {1, 1, 0, 1, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 0, 0}}};

    // When
    const std::int32_t number_of_islands{GetNumberOfIslands(graph)};

    // Then
    EXPECT_EQ(2, number_of_islands);
}
}  // namespace
}  // namespace problem_statement
