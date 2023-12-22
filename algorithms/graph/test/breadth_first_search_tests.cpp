///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/graph/breadth_first_search.h"
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
/// @test Test if correct shortest path is found between start-end locations using Breadth First Search algorithm.
///
TEST(BreadthFirstSearch, SearchShortestPath_GivenTypicalStartEndLocations_ExpectShortestPath)
{
    // Given
    const GridLocation start{0_m, 0_m};
    const GridLocation end{8_m, 5_m};
    BreadthFirstSearch<GridWithWeights, GridLocation> unit_{kGridWithWeightsDiagram};

    // When
    unit_.SearchShortestPath(start, end);

    // Then

    EXPECT_THAT(unit_.GetShortestPath(),
                ::testing::ElementsAre(start,
                                       GridLocation{0_m, 1_m},
                                       GridLocation{1_m, 1_m},
                                       GridLocation{1_m, 2_m},
                                       GridLocation{2_m, 2_m},
                                       GridLocation{2_m, 3_m},
                                       GridLocation{3_m, 3_m},
                                       GridLocation{3_m, 4_m},
                                       GridLocation{4_m, 4_m},
                                       GridLocation{4_m, 5_m},
                                       GridLocation{5_m, 5_m},
                                       GridLocation{6_m, 5_m},
                                       GridLocation{7_m, 5_m},
                                       end));
}


TEST(BreadthFirstSearch, SearchIslands_GivenTypicalGridMap_ExpectNumberOfIslands) {
    
}
}  // namespace
}  // namespace graph
