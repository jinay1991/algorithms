///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/tree/expression_tree.h"

#include <gtest/gtest.h>

namespace tree
{
namespace
{
template <typename T>
class ExpressionTreeFixtureT : public ::testing::TestWithParam<T>
{
};

struct TestStringParam
{
    // Given
    std::string expression;

    // Then
    std::string infix_expression;
    std::string prefix_expression;
    std::string postfix_expression;
};

using ExpressionTreeFixture_WithString = ExpressionTreeFixtureT<TestStringParam>;

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    ExpressionTree,
    ExpressionTreeFixture_WithString,
    ::testing::Values(
        //              expression                    , (expected) infix_expression         , (expected) prefix_expression         , (expected) postfix_expression
        TestStringParam{"1+2+4*7"                     , "1 + 2 + 4 * 7 "                    , "+ + 1 2 * 4 7 "                    , "1 2 + 4 7 * + "                    },
        TestStringParam{"(1^2^(3/4/5-6)^(7*8-9))"     , "1 ^ 2 ^ 3 / 4 / 5 - 6 ^ 7 * 8 - 9 ", "^ 1 ^ 2 ^ - / / 3 4 5 6 - * 7 8 9 ", "1 2 3 4 / 5 / 6 - 7 8 * 9 - ^ ^ ^ "}
));
// clang-format on

TEST_P(ExpressionTreeFixture_WithString, GivenTypicalExpression_ExpectExpressionTree)
{
    // Given
    const auto param = GetParam();
    ExpressionTree unit{};

    // When
    unit.Construct(param.expression);

    // Then
    EXPECT_EQ(unit.GetInfixExpression(), param.infix_expression);
    EXPECT_EQ(unit.GetPrefixExpression(), param.prefix_expression);
    EXPECT_EQ(unit.GetPostfixExpression(), param.postfix_expression);
}
}  // namespace
}  // namespace tree
