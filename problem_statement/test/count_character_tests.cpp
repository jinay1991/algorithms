///
/// @file
/// @copyright Copyright (C) 2023. MIT License
///
#include "problem_statement/count_character.h"

#include <gtest/gtest.h>

namespace problem_statement
{
namespace
{
struct TestInputParam
{
    // Given
    std::vector<std::string> words;
    std::string characters;

    // Then
    std::int32_t count;
};

using CountCharacter_WithInput = ::testing::TestWithParam<TestInputParam>;

INSTANTIATE_TEST_SUITE_P(
    CountCharacter,
    CountCharacter_WithInput,
    ::testing::Values(
        //                         words           ,       characters, (expected) count
        TestInputParam{   {"cat","bt","hat","tree"},          "atach",                6},
        TestInputParam{{"hello","world","leetcode"}, "welldonehoneyr",               10}
));

TEST_P(CountCharacter_WithInput, CountCharacter_GivenTypicalInputs_ExpectCount) {
    // Given
    const auto param = GetParam();

    // When
    const auto count = CountCharacter(param.words, param.characters);

    // Then
    EXPECT_EQ(count, param.count);
}

}  // namespace
}  // namespace problem_statement
