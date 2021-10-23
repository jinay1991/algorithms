///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/distance_between_nodes.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>

namespace problem_statement
{
namespace
{

template <typename T>
using Tree = std::vector<Node<T>>;

/* Generates Tree with following Nodes

            1
          /
        3
      /   \
     8     2
    / \
   13  5
*/
inline Tree<std::int32_t> GenerateTestTree() noexcept
{
    // Construct the nodes in a vector of pointers for convenience
    std::vector<Node<std::int32_t>> node_list(6);

    node_list.at(0UL).id = 1;
    node_list.at(1UL).id = 3;
    node_list.at(2UL).id = 8;
    node_list.at(3UL).id = 2;
    node_list.at(4UL).id = 13;
    node_list.at(5UL).id = 5;

    // Set children
    node_list.at(0UL).left = &node_list.at(1);

    node_list.at(1UL).left = &node_list.at(2);
    node_list.at(1UL).right = &node_list.at(3);

    node_list.at(2UL).left = &node_list.at(4);
    node_list.at(2UL).right = &node_list.at(5);

    return node_list;
}

template <typename T>
constexpr void Inorder(const Node<T>* node) noexcept
{
    if (node != nullptr)
    {
        Inorder(node->left);
        std::cout << " " << node->id;
        Inorder(node->right);
        std::cout << std::endl;
    }
}

TEST(Tree, Inorder)
{
    // Given
    const auto tree = GenerateTestTree();

    // Then
    Inorder(&tree.at(0UL));
}

TEST(Distance, TreeNodesRoot)
{
    const auto tree = GenerateTestTree();

    const auto distance = Distance<std::int32_t>(tree.at(0UL), 1, 2);

    EXPECT_EQ(distance, 1UL);
}

TEST(Distance, TreeNodesLowestCommonAncestor)
{
    const auto tree = GenerateTestTree();

    const auto distance = Distance<std::int32_t>(tree.at(0UL), 2, 5);

    EXPECT_EQ(distance, 2UL);
}

TEST(Distance, TreeNodesBFS)
{
    const auto tree = GenerateTestTree();

    const auto distance = Distance2<std::int32_t>(tree.at(0UL), 2, 5);

    EXPECT_EQ(distance, 2UL);
}

TEST(Distance, TreeNodesNear)
{
    const auto tree = GenerateTestTree();

    const auto distance = Distance<std::int32_t>(tree.at(0UL), 2, 3);

    EXPECT_EQ(distance, 0UL);
}

}  // namespace
}  // namespace problem_statement
