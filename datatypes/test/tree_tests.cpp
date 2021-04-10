///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "datatypes/tree.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

namespace datatypes
{
namespace
{
TEST(Tree, Insert_GivenSingleValue_ExpectInsertedValue)
{
    // Given
    Tree<std::int32_t> tree;
    const std::int32_t value = 1;

    // When
    tree.Insert(value);

    // Then
    EXPECT_EQ(tree.GetSize(), 1U);
    EXPECT_EQ(tree.GetHeight(), 1U);
    EXPECT_EQ(tree.GetWidth(), 1U);
    EXPECT_TRUE(tree.Contains(value));
}

class TreeFixture : public ::testing::Test
{
};

template <typename T>
class TreeFixtureT : public TreeFixture, public ::testing::WithParamInterface<T>
{
};

using TreeFixture_WithMultipleValues = TreeFixtureT<std::vector<std::int32_t>>;

INSTANTIATE_TEST_SUITE_P(Tree, TreeFixture_WithMultipleValues, ::testing::Values(std::vector<std::int32_t>{2, 1, 3}));

TEST_P(TreeFixture_WithMultipleValues, Insert_GivenMultipleValues_ExpectInsertedValues)
{
    // Given
    Tree<std::int32_t> tree;
    const auto list = GetParam();

    // When
    tree.Insert(list);

    std::cout << tree << std::endl;
    // Then
    EXPECT_EQ(tree.GetSize(), 3U);
}
}  // namespace
}  // namespace datatypes