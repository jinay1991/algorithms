///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ARGOAI_FIND_RIGHT_SIBLING_H
#define ARGOAI_FIND_RIGHT_SIBLING_H

#include <iostream>
#include <utility>
#include <vector>

namespace argoai
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

/// @brief Stream operator to sprint a pair of node pointers as specified
constexpr std::ostream& operator<<(std::ostream& stream, const std::pair<const Node*, const Node*>& pair) noexcept
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

}  // namespace argoai

#endif  /// ARGOAI_FIND_RIGHT_SIBLING_H