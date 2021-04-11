///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "common/algorithm/tree.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

namespace algorithm
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
}

class TreeFixture : public ::testing::Test
{
};

template <typename T>
class TreeFixtureT : public TreeFixture, public ::testing::WithParamInterface<T>
{
};

using TreeFixture_WithMultipleValues = TreeFixtureT<std::vector<std::int32_t>>;

INSTANTIATE_TEST_SUITE_P(Tree,
                         TreeFixture_WithMultipleValues,
                         ::testing::Values(std::vector<std::int32_t>{2, 1, 3},
                                           std::vector<std::int32_t>{2, 1, 3, 5, 6},
                                           std::vector<std::int32_t>{10, -5, 16, -8, 7, 18},
                                           std::vector<std::int32_t>{2, 1}));

TEST_P(TreeFixture_WithMultipleValues, Insert_GivenMultipleValues_ExpectInsertedValues)
{
    // Given
    Tree<std::int32_t> tree;
    const auto list = GetParam();

    // When
    tree.Insert(list);

    // Then
    EXPECT_EQ(tree.GetSize(), list.size());
}

}  // namespace
}  // namespace algorithm
