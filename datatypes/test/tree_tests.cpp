///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "datatypes/tree.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

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

TEST(Tree, Insert_GivenMultipleValues_ExpectInsertedValues)
{
    // Given
    Tree<std::int32_t> tree;
    const std::int32_t value_1 = 1;
    const std::int32_t value_2 = 2;
    const std::int32_t value_3 = 3;

    // When
    tree.Insert(value_1);
    tree.Insert(value_2);
    tree.Insert(value_3);

    std::cout << tree << std::endl;
    // Then
    EXPECT_EQ(tree.GetSize(), 3U);
}
}  // namespace
}  // namespace datatypes