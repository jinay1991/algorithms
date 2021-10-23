///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/string/postfix_expression.h"

#include <gtest/gtest.h>

namespace string
{
namespace
{
template <typename T>
class ToPostfixFixtureT : public ::testing::TestWithParam<T>
{
};

struct TestStringParam
{
    // Given
    std::string infix_expression;

    // Then
    std::string postfix_expression;
};

using ToPostfixFixture_WithString = ToPostfixFixtureT<TestStringParam>;

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    ToPostfix,
    ToPostfixFixture_WithString,
    ::testing::Values(
        ///             infix                                   , (expected) postfix
        TestStringParam{"3 + 4"                                 , "3 4 +"                            },
        TestStringParam{"3 + 4 * 12 - 10"                       , "3 4 12 * + 10 -"                  },
        TestStringParam{"1+2*(3^4-5)^(6+7*8)-9"                 , "1 2 3 4 ^ 5 - 6 7 8 * + ^ * + 9 -"}
));
// clang-format on

TEST_P(ToPostfixFixture_WithString, GivenTypicalInfixExpression_ExpectConvertedPostfixExpression)
{
    // Given
    const auto param = GetParam();

    // When
    const auto postfix_expression = ToPostfix(param.infix_expression);

    // Then
    EXPECT_EQ(postfix_expression, param.postfix_expression);
}
}  // namespace
}  // namespace string
