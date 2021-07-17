///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ARGOAI_FIND_RIGHT_SIBLING_H
#define ARGOAI_FIND_RIGHT_SIBLING_H

#include <iostream>
#include <utility>
#include <vector>

namespace problem_statement
{
/// @brief Node object that stores pointers to its parent and to left and right children
struct Node
{
    /// Identifier for the node
    int id;

    /// Parent
    Node* parent;

    /// Left child
    Node* left;

    /// Right child
    Node* right;
};

/// @brief Given the root of a binary tree, return all of the right-sibling pairs.
///        If a node has no right sibling, the second element of its pair should be null
std::vector<std::pair<const Node*, const Node*>> find_right_siblings(const Node& root);

}  // namespace problem_statement

#endif  /// ARGOAI_FIND_RIGHT_SIBLING_H
