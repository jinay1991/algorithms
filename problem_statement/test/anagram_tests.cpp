///
/// @test
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/anagram.h"

#include <gtest/gtest.h>

namespace problem_statement
{
class AnagramFixture : public ::testing::Test
{
};

template <typename T>
class AnagramFixtureT : public AnagramFixture, public ::testing::WithParamInterface<T>
{
};

struct TestStringParam
{
    // Given
    std::string s1;
    std::string s2;

    // Then
    bool is_anagram;
};

using AnagramFixture_WithString = AnagramFixtureT<TestStringParam>;

// clang-format off
INSTANTIATE_TEST_SUITE_P(
    Anagram,
    AnagramFixture_WithString,
    ::testing::Values(
        ///                         s1              ,               s2            , (expected) is_anagram
        TestStringParam{"rat"                       , "tar"                       ,                  true}, // (0)
        TestStringParam{"rat"                       , "tat"                       ,                 false}, // (1)
        TestStringParam{"rat"                       , "rar"                       ,                 false}, // (2)
        TestStringParam{"rat"                       , "aat"                       ,                 false}, // (3)
        TestStringParam{"rat"                       , "rrt"                       ,                 false}, // (4)
        TestStringParam{"abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxye",                 false}, // (5)
        TestStringParam{"abc"                       , "ABC"                       ,                 false}, // (6)
        TestStringParam{"abc"                       , "123"                       ,                 false}, // (7)
        TestStringParam{"123"                       , "abc"                       ,                 false}, // (8)
        TestStringParam{"123"                       , "123"                       ,                  true}, // (9)
        TestStringParam{"abc"                       , "abc"                       ,                  true}, // (10)
        TestStringParam{"abc"                       , "bac"                       ,                  true}, // (11)
        TestStringParam{"abc"                       , "bca"                       ,                  true}, // (12)
        TestStringParam{"abc"                       , "cab"                       ,                  true}, // (13)
        TestStringParam{"abc"                       , "abcd"                      ,                 false}  // (14)
));
// clang-format on

TEST_P(AnagramFixture_WithString, IsAnagram_GivenTypicalStringInputs_ExpectAnagramCheckStatus)
{
    // Given
    const auto param = GetParam();

    // When
    const auto is_anagram = IsAnagram(param.s1, param.s2);

    // Then
    EXPECT_EQ(is_anagram, param.is_anagram);
}
}  // namespace problem_statement
