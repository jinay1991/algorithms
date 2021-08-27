///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/graph/graph.h"

#include <gtest/gtest.h>

namespace graph
{
namespace
{
constexpr std::size_t kMaxNumberOfNodes = 10UL;

class GraphFixture : public ::testing::Test
{
  public:
    GraphFixture() : graph_{} {}

  protected:
    void SetUp() override
    {
        ///
        ///  Graph: Construct graph with following edges...
        ///
        ///  1 --> 2 --> 3 --> 4 --> 5 <-- 6
        ///        ^                 |
        ///         \---------------/
        ///

        graph_.AddEdge(1, 2);
        graph_.AddEdge(2, 3);
        graph_.AddEdge(3, 4);
        graph_.AddEdge(4, 5);
        graph_.AddEdge(5, 2);
        graph_.AddEdge(6, 5);
    }

    Graph<std::int32_t, kMaxNumberOfNodes> graph_;
};

template <typename T>
class GraphFixtureT : public GraphFixture, public ::testing::WithParamInterface<T>
{
};

struct TestRouteExistsParam
{
    // Given
    std::int32_t source;
    std::int32_t destination;

    // Then
    bool exists;
};

using GraphFixture_WithRouteExists = GraphFixtureT<TestRouteExistsParam>;

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    Graph,
    GraphFixture_WithRouteExists,
    ::testing::Values(
        ///                  source, destination, (expected) exists
        TestRouteExistsParam{     1,           3,              true},
        TestRouteExistsParam{     1,           2,              true},
        TestRouteExistsParam{     1,           4,              true},
        TestRouteExistsParam{     1,           5,              true},
        TestRouteExistsParam{     1,           6,             false},
        TestRouteExistsParam{     2,           1,             false},
        TestRouteExistsParam{     5,           1,             false},
        TestRouteExistsParam{     5,           2,              true},
        TestRouteExistsParam{     5,           3,              true},
        TestRouteExistsParam{     5,           4,              true},
        TestRouteExistsParam{     5,           5,              true}
));
// clang-format on

TEST_P(GraphFixture_WithRouteExists, IsRouteExists_GivenTypicalGraph_ExpectTrue)
{
    // Given
    const auto param = GetParam();

    // When
    const auto exists = graph_.IsRouteExists(param.source, param.destination);

    // Then
    EXPECT_EQ(exists, param.exists);
}
}  // namespace
}  // namespace graph
