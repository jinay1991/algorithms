///
/// @file
/// @copyright Copyright (C) 2023. MIT License.
///
#include "problem_statement/find_kth_max_element.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>

namespace problem_statement
{
namespace
{

TEST(FindKthMaxElementFixture, GivenTypicalInputArray_ExpectError)
{
    // Given
    constexpr std::size_t kMaxElements{5UL};
    const std::array<std::int32_t, kMaxElements> input_array{12, 3, 5, 7, 19};

    // When
    constexpr std::size_t K{kMaxElements + 1UL};
    const auto kth_element = find_kth_max_element(input_array, K);

    // Then
    EXPECT_EQ(kth_element, std::numeric_limits<std::int32_t>::infinity());
}

TEST(FindKthMaxElementFixture, GivenTypicalInputArrayWithZeroK_ExpectError)
{
    // Given
    constexpr std::size_t kMaxElements{5UL};
    const std::array<std::int32_t, kMaxElements> input_array{12, 3, 5, 7, 19};

    // When
    constexpr std::size_t K{0UL};
    const auto kth_element = find_kth_max_element(input_array, K);

    // Then
    EXPECT_EQ(kth_element, std::numeric_limits<std::int32_t>::infinity());
}

TEST(FindKthMaxElementFixture, GivenTypicalInputArray_ExpectKthMaxElement)
{
    // Given
    constexpr std::size_t kMaxElements{8UL};
    const std::array<std::int32_t, kMaxElements> input_array{12, 3, 5, 7, 19, 4, 9, 6};

    // When
    constexpr std::size_t K{6UL};
    const auto kth_element = find_kth_max_element(input_array, K);

    // Then
    EXPECT_EQ(kth_element, 5);
}
}  // namespace
}  // namespace problem_statement
