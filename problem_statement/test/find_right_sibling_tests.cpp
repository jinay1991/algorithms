///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/find_right_sibling.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <ostream>
#include <utility>

namespace problem_statement
{
namespace
{
class FindRightSiblingFixture : public ::testing::Test
{
  protected:
    /// @brief Function to make our test tree. It is complete, and you do not need to modify it.
    /// @return A vector of nodes for the following tree, with the root at the front of the vector.
    /*             0
     *            / \
     *           1   5
     *          /   / \
     *         2   6   9
     *        /   / \   \
     *       3   7   8   10
     *      /             \
     *     4               11
     */
    inline std::vector<Node> GenerateTestTree() const noexcept
    {
        // Construct the nodes in a vector of pointers for convenience
        std::vector<Node> node_list(12);

        // Set the IDs
        for (size_t i = 0; i < node_list.size(); ++i)
        {
            node_list[i].id = i;
        }

        // Set children
        node_list.at(0).left = &node_list.at(1);
        node_list.at(0).right = &node_list.at(5);
        node_list.at(1).left = &node_list.at(2);
        node_list.at(2).left = &node_list.at(3);
        node_list.at(3).left = &node_list.at(4);
        node_list.at(5).left = &node_list.at(6);
        node_list.at(5).right = &node_list.at(9);
        node_list.at(6).left = &node_list.at(7);
        node_list.at(6).right = &node_list.at(8);
        node_list.at(9).right = &node_list.at(10);
        node_list.at(10).right = &node_list.at(11);

        // Set parents
        node_list.at(1).parent = &node_list.at(0);
        node_list.at(2).parent = &node_list.at(1);
        node_list.at(3).parent = &node_list.at(2);
        node_list.at(4).parent = &node_list.at(3);
        node_list.at(5).parent = &node_list.at(0);
        node_list.at(6).parent = &node_list.at(5);
        node_list.at(7).parent = &node_list.at(6);
        node_list.at(8).parent = &node_list.at(7);
        node_list.at(9).parent = &node_list.at(5);
        node_list.at(10).parent = &node_list.at(9);
        node_list.at(11).parent = &node_list.at(10);

        // Return root
        return node_list;
    }
};

/// @brief Stream operator to sprint a pair of node pointers as specified
inline std::ostream& operator<<(std::ostream& stream, const std::pair<const Node*, const Node*>& pair) noexcept
{
    if (pair.first != nullptr)
    {
        stream << pair.first->id;
    }
    else
    {
        stream << "None";
    }
    std::cout << " -> ";
    if (pair.second != nullptr)
    {
        stream << pair.second->id;
    }
    else
    {
        stream << "None";
    }
    return stream;
}

/** Find the "right siblings" in a binary tree.
 *  For example, this tree:
 *              0
 *             / \
 *            1   5
 *           /   / \
 *          2   6   9
 *         /   / \   \
 *        3   7   8   10
 *       /             \
 *      4               11
 *  Expected Output:
 *  0 -> None
 *  1 -> 5
 *  5 -> None
 *  2 -> 6
 *  6 -> 9
 *  9 -> None
 *  3 -> 7
 *  7 -> 8
 *  8 -> 10
 *  10 -> None
 *  4 -> 11
 *  11 -> None
 */
TEST_F(FindRightSiblingFixture, GivenTypicalTestTree_ExpectRightSiblings)
{
    // Given
    const auto test_tree = GenerateTestTree();

    // When
    const auto pairs = find_right_siblings(test_tree.at(0U));

    // Then
    EXPECT_EQ(pairs.size(), 12U);
    for (const auto& sibling_pair : pairs)
    {
        std::cout << sibling_pair << std::endl;
    }
}
}  // namespace
}  // namespace problem_statement
