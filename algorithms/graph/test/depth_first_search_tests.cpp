///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/graph/depth_first_search.hpp"
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

TEST(DepthFirstSearch, GivenTypicalGraph_ExpectDepthFirstSearch)
{
    /// Given
    const GridLocation start{0_m, 0_m};
    const GridLocation end{8_m, 5_m};
    DepthFirstSearch<GridWithWeights, GridLocation> unit{kGridWithWeightsDiagram};

    // When
    unit.SearchShortestPath(start, end);

    // Then
    EXPECT_THAT(unit.GetShortestPath(),
                ::testing::ElementsAre(start,
                                       GridLocation{1_m, 0_m},
                                       GridLocation{1_m, 1_m},
                                       GridLocation{2_m, 1_m},
                                       GridLocation{2_m, 2_m},
                                       GridLocation{3_m, 2_m},
                                       GridLocation{3_m, 3_m},
                                       GridLocation{4_m, 3_m},
                                       GridLocation{4_m, 4_m},
                                       GridLocation{5_m, 4_m},
                                       GridLocation{5_m, 5_m},
                                       GridLocation{6_m, 5_m},
                                       GridLocation{6_m, 6_m},
                                       GridLocation{7_m, 6_m},
                                       GridLocation{7_m, 7_m},
                                       GridLocation{8_m, 7_m},
                                       GridLocation{9_m, 7_m},
                                       GridLocation{9_m, 6_m},
                                       GridLocation{9_m, 5_m},
                                       end));
}

}  // namespace
}  // namespace graph
