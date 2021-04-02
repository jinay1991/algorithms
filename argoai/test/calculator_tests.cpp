///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "argoai/calculator.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

namespace argoai
{
namespace
{

struct TestStringParam
{
    // Given
    std::string input;

    // Then
    double result;
};

class CalculatorFixture_WithStringInput : public ::testing::TestWithParam<TestStringParam>
{
};

INSTANTIATE_TEST_SUITE_P(Calculator,
                         CalculatorFixture_WithStringInput,
                         ::testing::Values(
                             //
                             TestStringParam{"1+2", 3.0},
                             TestStringParam{"10*20", 200.0},
                             TestStringParam{"5-1/5+16+4*3", 0.0}));

TEST_P(CalculatorFixture_WithStringInput, GivenTypicalString_ExpectCalculatedResult)
{
    // Given
    const auto param = GetParam();

    // When
    const auto result = calculate(param.input);

    // Then
    EXPECT_DOUBLE_EQ(result, param.result);
}
}  // namespace
}  // namespace argoai