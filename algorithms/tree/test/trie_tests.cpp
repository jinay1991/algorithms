///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/tree/trie.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>

namespace tree
{
namespace
{

TEST(Trie, Insert_GivenWord_ExpectInserted)
{
    // Given
    const std::string word = "art";
    Trie unit{};

    // When
    unit.Insert(word);

    // Then
    EXPECT_TRUE(unit.HasWord(word));
}

TEST(Trie, InsertDictionary_GivenDictionary_ExpectInserted)
{
    // Given
    const std::vector<std::string> words = {"art",
                                            "zone",
                                            "zip",
                                            "arts",
                                            "date",
                                            "z",
                                            "day",
                                            "articles",
                                            "data",
                                            "catch",
                                            "zoom",
                                            "article",
                                            "articulate",
                                            "articulation"};
    Trie unit{};

    // When
    unit.InsertDictionary(words);

    // Then
    EXPECT_TRUE(unit.HasWord("zone"));
    EXPECT_TRUE(unit.HasWord("zoom"));
    EXPECT_TRUE(unit.HasWord("articulation"));
    EXPECT_TRUE(unit.HasWord("day"));
    EXPECT_TRUE(unit.HasWord("catch"));
    EXPECT_FALSE(unit.HasWord("catc"));
}

TEST(Trie, GetSuggestions_GivenDictionary_ExpectSuggestions)
{
    // Given
    const std::vector<std::string> words = {"art",
                                            "zone",
                                            "zip",
                                            "arts",
                                            "date",
                                            "z",
                                            "day",
                                            "articles",
                                            "data",
                                            "catch",
                                            "zoom",
                                            "article",
                                            "articulate",
                                            "articulation"};
    Trie unit{};
    unit.InsertDictionary(words);

    // When
    const auto suggestions = unit.GetSuggestions("art", 4UL);

    // Then
    EXPECT_EQ(suggestions.size(), 6UL);
    EXPECT_THAT(suggestions,
                ::testing::ElementsAreArray({"art", "article", "articles", "articulate", "articulation", "arts"}));
}
}  // namespace
}  // namespace tree
