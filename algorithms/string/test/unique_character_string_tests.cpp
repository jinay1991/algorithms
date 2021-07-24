///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/string/unique_character_string.h"

#include <gtest/gtest.h>

namespace string
{
namespace
{

struct TestStringParam
{
    // Given
    std::string input;

    // Then
    bool is_unique;
};

class IsUniqueCharacterStringFixture_WithString : public ::testing::TestWithParam<TestStringParam>
{
};

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    IsUniqueCharacterString,
    IsUniqueCharacterStringFixture_WithString,
    ::testing::Values(
        //              input                                 , (expected) is_unique
        TestStringParam{"test"                                ,                false},
        TestStringParam{"test12"                              ,                false},
        TestStringParam{"testt"                               ,                false},
        TestStringParam{"0123456789abcdefghijklmnopqrstuvwxyz",                 true},
        TestStringParam{"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",                 true},
        TestStringParam{";"                                   ,                 true},
        TestStringParam{""                                    ,                 true}
));
// clang-format on

TEST_P(IsUniqueCharacterStringFixture_WithString, GivenTypicalString_ExpectIsUniqueCharacterStringStatus)
{
    // Given
    const auto param = GetParam();

    // When
    const auto is_unique = IsUniqueCharacterString(param.input);

    // Then
    EXPECT_EQ(is_unique, param.is_unique);
}

}  // namespace
}  // namespace string
