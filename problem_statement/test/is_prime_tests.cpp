///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/is_prime.h"

#include <gtest/gtest.h>

namespace problem_statement
{
namespace
{

struct TestValueParam
{
    // Given
    std::int32_t value;

    // Then
    bool is_prime;
};

using IsPrimeFixture_WithValue = ::testing::TestWithParam<TestValueParam>;

INSTANTIATE_TEST_SUITE_P(IsPrime,
                         IsPrimeFixture_WithValue,
                         ::testing::Values(TestValueParam{1, true},
                                           TestValueParam{2, true},
                                           TestValueParam{3, true},
                                           TestValueParam{4, false},
                                           TestValueParam{5, true},
                                           TestValueParam{6, false},
                                           TestValueParam{7, true},
                                           TestValueParam{8, false},
                                           TestValueParam{9, true},
                                           TestValueParam{10, false},
                                           TestValueParam{11, true},
                                           TestValueParam{12, false},
                                           TestValueParam{13, true},
                                           TestValueParam{14, false}));

TEST_P(IsPrimeFixture_WithValue, IsPrime_GivenTypicalValue_ExpectIsPrime)
{
    // Given
    const auto param = GetParam();

    // When
    const auto is_prime = IsPrime(param.value);

    // Then
    EXPECT_EQ(is_prime, param.is_prime);
}
}  // namespace
}  // namespace problem_statement
