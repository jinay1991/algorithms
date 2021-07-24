///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/calculator.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

namespace problem_statement
{
namespace
{

struct TestStringParam
{
    // Given
    std::string expression;

    // Then
    double result;
};

class CalculatorFixture_WithExpression : public ::testing::TestWithParam<TestStringParam>
{
};
// clang-format off
INSTANTIATE_TEST_SUITE_P(
    Calculator,
    CalculatorFixture_WithExpression,
    ::testing::Values(
        //              expression              , (expected) result
        TestStringParam{"1+2"                   ,       3.0       }, // (0)
        TestStringParam{"10*20"                 ,       200.0     }, // (1)
        TestStringParam{"5-1/5+16+4*3"          ,       32.79     }, // (2)
        TestStringParam{"10 + 2 * 6"            ,       22.0      }, // (3)
        TestStringParam{"100 * ( 2 + 12 ) / 14" ,       100.0     }, // (4)
        TestStringParam{"100 * ( 2 + 12 )"      ,       1400.0    }, // (5)
        TestStringParam{"100 * 2 + 12"          ,       212.0     }  // (6)
));
// clang-format on

TEST_P(CalculatorFixture_WithExpression, GivenTypicalString_ExpectCalculatedResult)
{
    // Given
    const auto param = GetParam();

    // When
    const auto result = calculate(param.expression);

    // Then
    EXPECT_NEAR(result, param.result, 0.01);
}
}  // namespace
}  // namespace problem_statement
