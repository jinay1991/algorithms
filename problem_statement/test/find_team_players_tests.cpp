///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/find_team_players.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

namespace problem_statement
{
namespace
{

struct TestInputParam
{
    // Given
    std::initializer_list<std::pair<std::string, std::string>> input;
    std::pair<std::string, std::string> query;

    // Then
    bool result;
};

class FindTeamPlayersFixture_WithInputs : public ::testing::TestWithParam<TestInputParam>
{
};

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    FindTeamPlayers,
    FindTeamPlayersFixture_WithInputs,
    ::testing::Values(
        //                                          input                            ,         query         , (expected) result
        TestInputParam{{{"rashford", "pogba"}, {"pogba", "cavani"}, {"pepe", "saka"}}, {"rashford", "cavani"},             true}
));
// clang-format on

TEST_P(FindTeamPlayersFixture_WithInputs, IsConnected_GivenTypicalListOfPair_ExpectConnection)
{
    // Given
    const auto param = GetParam();
    Graph<std::string> unit{param.input};

    // When
    const auto result = unit.Query(param.query.first, param.query.second);

    // Then
    EXPECT_EQ(result, param.result);
}
}  // namespace
}  // namespace problem_statement
