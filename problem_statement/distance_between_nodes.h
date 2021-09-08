///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///

/*
I want you to find the distance between two nodes in a ordered binary tree.
Distance in this case being how many nodes are between the two nodes if you traverse the tree.

So for example if you have a tree build from something like:
tree.insert(1)
tree.insert(3)
tree.insert(2)
tree.insert(8)
tree.insert(5)
tree.insert(13)
            1
          /
        3
      /   \
     8     2
    / \
   13  5
numberOfNodesBetween(1, 2) == 1 because there is one node (3) between 1 and 2
numberOfNodesBetween(5, 2) == 2 because there are two nodes (8 and 3) between 5 and 2
*/

#ifndef PROBLEM_STATEMENT_DISTANCE_BETWEEN_NODES_H
#define PROBLEM_STATEMENT_DISTANCE_BETWEEN_NODES_H

#include <cstdint>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <utility>
#include <vector>

namespace problem_statement
{

template <typename T>
struct Node
{
    /// Identifier for the node
    T id{0};

    /// Left child
    Node<T>* left{nullptr};

    /// Right child
    Node<T>* right{nullptr};
};

template <typename T>
constexpr const Node<T>* LowestCommonAncestor(const Node<T>* node, const T& id_1, const T& id_2) noexcept
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->id == id_1 || node->id == id_2)
    {
        return node;
    }

    const Node<T>* left = LowestCommonAncestor(node->left, id_1, id_2);
    const Node<T>* right = LowestCommonAncestor(node->right, id_1, id_2);

    if (left != nullptr && right != nullptr)
    {
        return node;
    }

    if (left == nullptr && right == nullptr)
    {
        return nullptr;
    }

    if (left != nullptr)
    {
        return left;
    }
    return right;
}

template <typename T>
constexpr std::int32_t FindLevel(const Node<T>* node, const T& id, const std::int32_t level) noexcept
{
    if (node == nullptr)
    {
        return -1;
    }

    if (node->id == id)
    {
        return level;
    }

    const auto left = FindLevel(node->left, id, level + 1UL);
    if (left != -1)  // found on left
    {
        return left;
    }
    return FindLevel(node->right, id, level + 1UL);
}

template <typename T>
constexpr std::size_t Distance(const Node<T>& root, const T& start_id, const T& end_id) noexcept
{
    const Node<T>* lca = LowestCommonAncestor<T>(&root, start_id, end_id);

    const auto distance_between_lca_and_start = FindLevel<T>(lca, start_id, 0);
    const auto distance_between_lca_and_end = FindLevel<T>(lca, end_id, 0);

    const auto distance_between_start_and_end = distance_between_lca_and_start + distance_between_lca_and_end - 1;

    return distance_between_start_and_end;
}

template <typename T>
std::size_t Distance2(const Node<T>& root, const T& start_id, const T& end_id) noexcept
{
    std::queue<const Node<T>*> queue;
    queue.push(&root);

    std::size_t level = 0UL;

    std::size_t distance_between_root_and_end = 0UL;
    std::size_t distance_between_root_and_start = 0UL;
    std::size_t distance_between_root_and_lca = 0UL;

    const Node<T>* lca_node = LowestCommonAncestor(&root, start_id, end_id);

    while (!queue.empty())
    {
        const auto number_of_nodes_in_current_level = queue.size();
        for (auto i = 0UL; i < number_of_nodes_in_current_level; ++i)
        {
            const auto current = queue.front();
            queue.pop();

            if (current->id == lca_node->id)
            {
                distance_between_root_and_lca = level;
            }

            if (current->id == end_id)
            {
                distance_between_root_and_end = level;
            }

            if (current->id == start_id)
            {
                distance_between_root_and_start = level;
            }

            if (current->left)
            {
                queue.push(current->left);
            }
            if (current->right)
            {
                queue.push(current->right);
            }
        }

        level++;
    }

    return ((distance_between_root_and_end + distance_between_root_and_start) - (2UL * distance_between_root_and_lca) -
            1UL);
}

// template <typename T>
// size_t distance(const Tree<T>& root, const T& node_1, const T& node_2)
// {
//     std::queue<T> queue;
//     std::vector<std::pair<T, bool>> visited;

//     const T start_node = std::min(node_1, node_2);  // min
//     const T end_node = std::max(node_1, node_2);    // max

//     int count = 0;
//     bool is_start_found = false;
//     queue.push(root);

//     while (!queue.empty())
//     {

//         //
//         if (!is_start_found)
//         {
//             const auto size = queue.size();
//             for (auto i = 0; i < size; ++i)
//             {
//                 const auto node = queue.top();
//                 queue.pop();

//                 if (node == start_node)
//                 {
//                     count++;
//                     is_start_found = true;
//                     break;
//                 }

//                 if (node->right)
//                 {
//                     queue.push(node->right);
//                 }
//                 if (node->left)
//                 {
//                     queue.push(node->left);
//                 }
//             }
//         }
//         else
//         {
//             const auto node = queue.top();
//             queue.pop();

//             if (node == end_node)
//             {
//                 count++;
//                 break;
//             }
//             count++;
//             if (node->right)
//             {
//                 queue.push(node->right);
//             }
//             if (node->left)
//             {
//                 queue.push(node->left);
//             }
//         }

//         // if (node->right) {
//         //     is_start_node_found = (node->right == start_node);
//         //     queue.push(node->right);
//         // }

//         // if (node->left) {
//         //     is_start_node_found = (node->left == start_node);
//         //     queue.push(node->left);
//         // }

//         // if (is_start_node_found)
//         // {
//         //     count++;
//         // }
//     }
//     return count;
// }

}  // namespace problem_statement

#endif  /// PROBLEM_STATEMENT_DISTANCE_BETWEEN_NODES_H
