///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/graph/test/support/simple_graph.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace graph
{
namespace
{

TEST(SimpleGraph, AddEdge_GivenTypicalInputs_ExpectUpdatedEdge)
{
    // Given
    SimpleGraph<char> simple_graph{};
    ASSERT_THAT(simple_graph.GetNeighbors('a'), ::testing::IsEmpty());

    // When
    simple_graph.AddEdge('a', {'b'});

    // Then
    EXPECT_THAT(simple_graph.GetNeighbors('a'), ::testing::ElementsAre('a', 'b'));
    EXPECT_THAT(simple_graph.GetNeighbors('b'), ::testing::IsEmpty());
}

TEST(SimpleGraph, AddEdge)
{
    // Given
    SimpleGraph<char> simple_graph{};
    ASSERT_THAT(simple_graph.GetNeighbors('a'), ::testing::IsEmpty());

    // When
    simple_graph.AddEdge('a', {'b'});
    simple_graph.AddEdge('a', {'c'});

    // Then
    EXPECT_THAT(simple_graph.GetNeighbors('a'), ::testing::ElementsAre('a', 'b'));
    EXPECT_THAT(simple_graph.GetNeighbors('b'), ::testing::IsEmpty());
}
}  // namespace
}  // namespace graph
