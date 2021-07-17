///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/graph/astar.h"
#include "algorithms/graph/test/support/grid_location.h"
#include "algorithms/graph/test/support/test_data.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <units.h>

namespace graph
{
namespace
{
using namespace units::literals;

///
/// @test Test if correct shortest path is found between start-end locations using A* algorithm.
///
TEST(AStar, SearchShortestPath_GivenTypicalStartEndLocations_ExpectShortestPath)
{
    // Given
    const GridLocation start{0_m, 0_m};
    const GridLocation end{8_m, 5_m};
    AStar<GridWithWeights, GridLocation> unit_{kGridWithWeightsDiagram};

    // When
    unit_.SearchShortestPath(start, end);

    // Then
    EXPECT_THAT(unit_.GetShortestPath(),
                ::testing::ElementsAre(start,
                                       GridLocation{1_m, 0_m},
                                       GridLocation{2_m, 0_m},
                                       GridLocation{3_m, 0_m},
                                       GridLocation{4_m, 0_m},
                                       GridLocation{5_m, 0_m},
                                       GridLocation{6_m, 0_m},
                                       GridLocation{6_m, 1_m},
                                       GridLocation{7_m, 1_m},
                                       GridLocation{7_m, 2_m},
                                       GridLocation{8_m, 2_m},
                                       GridLocation{8_m, 3_m},
                                       GridLocation{8_m, 4_m},
                                       end));
}
}  // namespace
}  // namespace graph
