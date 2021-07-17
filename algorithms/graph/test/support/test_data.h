///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_GRAPH_TEST_SUPPORT_TEST_DATA_H
#define ALGORITHMS_GRAPH_TEST_SUPPORT_TEST_DATA_H

#include "algorithms/graph/test/support/grid_location.h"
#include "algorithms/graph/test/support/grid_with_weights_builder.h"
#include "algorithms/graph/test/support/simple_graph_builder.h"
#include "algorithms/graph/test/support/square_grid_builder.h"

#include <units.h>

namespace graph
{

using namespace units::literals;

static const SimpleGraph<char> kSampleGraph = SimpleGraphBuilder<char>()
                                                  .WithEdge('A', {'B'})
                                                  .WithEdge('B', {'C'})
                                                  .WithEdge('C', {'B', 'D', 'F'})
                                                  .WithEdge('D', {'C', 'E'})
                                                  .WithEdge('E', {'F'})
                                                  .WithEdge('F', {})
                                                  .Build();

static const SquareGrid kSquareGridDiagram = SquareGridBuilder(30_m, 15_m)
                                                 .WithBlock(GridLocation{13_m, 4_m}, GridLocation{15_m, 15_m})
                                                 .WithBlock(GridLocation{21_m, 0_m}, GridLocation{23_m, 7_m})
                                                 .WithBlock(GridLocation{21_m, 0_m}, GridLocation{23_m, 7_m})
                                                 .WithBlock(GridLocation{23_m, 5_m}, GridLocation{26_m, 7_m})
                                                 .Build();

static const GridWithWeights kGridWithWeightsDiagram =
    GridWithWeightsBuilder(10_m, 10_m)
        .WithBlock(GridLocation{1_m, 7_m}, GridLocation{4_m, 9_m})
        .WithForestList({GridLocation{3_m, 4_m}, GridLocation{3_m, 5_m}, GridLocation{4_m, 1_m}, GridLocation{4_m, 2_m},
                         GridLocation{4_m, 3_m}, GridLocation{4_m, 4_m}, GridLocation{4_m, 5_m}, GridLocation{4_m, 6_m},
                         GridLocation{4_m, 7_m}, GridLocation{4_m, 8_m}, GridLocation{5_m, 1_m}, GridLocation{5_m, 2_m},
                         GridLocation{5_m, 3_m}, GridLocation{5_m, 4_m}, GridLocation{5_m, 5_m}, GridLocation{5_m, 6_m},
                         GridLocation{5_m, 7_m}, GridLocation{5_m, 8_m}, GridLocation{6_m, 2_m}, GridLocation{6_m, 3_m},
                         GridLocation{6_m, 4_m}, GridLocation{6_m, 5_m}, GridLocation{6_m, 6_m}, GridLocation{6_m, 7_m},
                         GridLocation{7_m, 3_m}, GridLocation{7_m, 4_m}, GridLocation{7_m, 5_m}})
        .Build();

}  // namespace graph

#endif  /// ALGORITHMS_GRAPH_TEST_SUPPORT_TEST_DATA_H
