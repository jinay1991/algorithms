///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/tree/binary_tree.h"

#include <gtest/gtest.h>

#include <iostream>
#include <limits>

namespace tree
{
namespace
{
static constexpr std::size_t kMaxNumberOfNodes = 10UL;

class TreeFixture : public ::testing::Test
{
};

template <typename T>
class TreeFixtureT : public TreeFixture, public ::testing::WithParamInterface<T>
{
};

TEST_F(TreeFixture, Insert_GivenTypicalNodes_ExpectUpdatedTree)
{
    // Given
    Tree<std::int32_t, kMaxNumberOfNodes> unit{};

    // When
    unit.Insert(3);
    unit.Insert(1);
    unit.Insert(2);

    // Then
    EXPECT_EQ(unit.GetSize(), 3UL);
    EXPECT_EQ(unit.GetCapacity(), kMaxNumberOfNodes);
    EXPECT_EQ(unit.GetMaxDepth(), 2UL);
    EXPECT_EQ(unit.GetMaxValue(), 3);
    EXPECT_EQ(unit.GetMinValue(), 1);
    EXPECT_TRUE(unit.IsBinarySearchTree());

    std::cout << "PreOrder Traversal: " << unit.GetPreOrderTraversal() << std::endl;
}
}  // namespace
}  // namespace tree
