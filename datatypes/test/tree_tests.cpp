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
TEST(Tree, Insert_GivenTypicalValue_ExpectInsertedValue)
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
}  // namespace
}  // namespace datatypes