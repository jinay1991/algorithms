///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/tree/binary_tree.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <limits>
#include <numeric>

namespace tree
{
namespace
{

static constexpr std::size_t kMaxNumberOfNodes = 15UL;

class TreeFixture : public ::testing::Test
{
};

template <typename T>
class TreeFixtureT : public TreeFixture, public ::testing::WithParamInterface<T>
{
};

TEST_F(TreeFixture, Insert_GivenTypicalNodes_ExpectTreeProperty)
{
    // Given
    Tree<std::int32_t, kMaxNumberOfNodes> unit{};

    // When
    unit.Insert(3);
    unit.Insert(2);
    unit.Insert(5);
    unit.Insert(1);

    // Then
    EXPECT_EQ(unit.GetSize(), 4UL);
    EXPECT_EQ(unit.GetCapacity(), kMaxNumberOfNodes);
    EXPECT_EQ(unit.GetMaxDepth(), 3UL);
    EXPECT_EQ(unit.GetMaxValue(), 5);
    EXPECT_EQ(unit.GetMinValue(), 1);
    EXPECT_TRUE(unit.IsBinarySearchTree());
    EXPECT_TRUE(unit.IsMinimalBinaryTree());
    EXPECT_TRUE(unit.IsBalancedBinaryTree());
    EXPECT_FALSE(unit.IsPerfectBinaryTree());
    EXPECT_FALSE(unit.IsFullBinaryTree());
    EXPECT_TRUE(unit.IsCompleteBinaryTree());
    EXPECT_THAT(unit.GetInOrderTraversal(), ::testing::ElementsAre(1, 2, 3, 5));
    EXPECT_THAT(unit.GetPreOrderTraversal(), ::testing::ElementsAre(3, 1, 2, 5));
    EXPECT_THAT(unit.GetPostOrderTraversal(), ::testing::ElementsAre(1, 2, 5, 3));
    EXPECT_THAT(unit.GetLevelOrderTraversal(), ::testing::ElementsAre(3, 2, 5, 1));
    EXPECT_THAT(unit.GetLeftViewTraversal(), ::testing::ElementsAre(3, 2, 1));
    EXPECT_THAT(unit.GetRightViewTraversal(), ::testing::ElementsAre(3, 5, 1));
    EXPECT_THAT(unit.GetTopViewTraversal(), ::testing::ElementsAre(3, 2, 5, 1));
    EXPECT_THAT(unit.GetBottomViewTraversal(), ::testing::ElementsAre(5, 1));
}

TEST_F(TreeFixture, InsertFromList_GivenTypicalListOfNodes_ExpectIncompleteBinaryTreeProperty)
{
    // Given
    Tree<std::int32_t, kMaxNumberOfNodes> unit{};
    const std::initializer_list<std::int32_t> list{10, 5, 20, 3, 7, 30};

    // When
    unit.InsertFromList(list);

    // Then
    EXPECT_EQ(unit.GetSize(), list.size());
    EXPECT_EQ(unit.GetCapacity(), kMaxNumberOfNodes);
    EXPECT_EQ(unit.GetMaxDepth(), 3UL);
    EXPECT_EQ(unit.GetMaxValue(), std::max(list));
    EXPECT_EQ(unit.GetMinValue(), std::min(list));
    EXPECT_TRUE(unit.IsBinarySearchTree());
    EXPECT_TRUE(unit.IsMinimalBinaryTree());
    EXPECT_TRUE(unit.IsBalancedBinaryTree());
    EXPECT_FALSE(unit.IsPerfectBinaryTree());
    EXPECT_FALSE(unit.IsFullBinaryTree());
    EXPECT_FALSE(unit.IsCompleteBinaryTree());
    EXPECT_THAT(unit.GetInOrderTraversal(), ::testing::ElementsAre(3, 5, 7, 10, 20, 30));
    EXPECT_THAT(unit.GetArrayIndexTraversal(), ::testing::ElementsAre(10, 5, 20, 3, 7, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0));
    EXPECT_THAT(unit.GetLeftViewTraversal(), ::testing::ElementsAre(10, 5, 3));
    EXPECT_THAT(unit.GetRightViewTraversal(), ::testing::ElementsAre(10, 20, 30));
    EXPECT_THAT(unit.GetTopViewTraversal(), ::testing::ElementsAre(10, 5, 20, 3, 30));
    EXPECT_THAT(unit.GetBottomViewTraversal(), ::testing::ElementsAre(3, 7, 30));
}

TEST_F(TreeFixture, InsertFromList_GivenTypicalListOfNodes_ExpectCompleteBinaryTreeProperty)
{
    // Given
    Tree<std::int32_t, kMaxNumberOfNodes> unit{};
    const std::initializer_list<std::int32_t> list{8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};

    // When
    unit.InsertFromList(list);

    // Then
    EXPECT_EQ(unit.GetSize(), list.size());
    EXPECT_EQ(unit.GetCapacity(), kMaxNumberOfNodes);
    EXPECT_EQ(unit.GetMaxDepth(), 4UL);
    EXPECT_EQ(unit.GetMaxValue(), std::max(list));
    EXPECT_EQ(unit.GetMinValue(), std::min(list));
    EXPECT_TRUE(unit.IsBinarySearchTree());
    EXPECT_TRUE(unit.IsMinimalBinaryTree());
    EXPECT_TRUE(unit.IsBalancedBinaryTree());
    EXPECT_TRUE(unit.IsPerfectBinaryTree());
    EXPECT_TRUE(unit.IsFullBinaryTree());
    EXPECT_TRUE(unit.IsCompleteBinaryTree());
    EXPECT_THAT(unit.GetInOrderTraversal(), ::testing::ElementsAre(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15));
    EXPECT_THAT(unit.GetLevelOrderTraversal(),
                ::testing::ElementsAre(8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15));
    EXPECT_THAT(unit.GetArrayIndexTraversal(),
                ::testing::ElementsAre(8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15));
    EXPECT_THAT(unit.GetLeftViewTraversal(), ::testing::ElementsAre(8, 4, 2, 1));
    EXPECT_THAT(unit.GetRightViewTraversal(), ::testing::ElementsAre(8, 12, 14, 15));
    EXPECT_THAT(unit.GetTopViewTraversal(), ::testing::ElementsAre(8, 4, 12, 2, 14, 1, 15));
    EXPECT_THAT(unit.GetBottomViewTraversal(), ::testing::ElementsAre(1, 3, 5, 7, 9, 11, 13, 15));
}
}  // namespace
}  // namespace tree
