///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "argoai/find_right_sibling.h"

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

namespace argoai
{

/// @brief Given the root of a binary tree, return all of the right-sibling pairs.
/// If a node has no right sibling, the second element of its pair should be null
std::vector<std::pair<const Node*, const Node*>> find_right_siblings(const Node& root)
{
    std::vector<std::pair<const Node*, const Node*>> right_siblings;
    std::queue<const Node*> node_queue;

    node_queue.push(&root);

    while (!node_queue.empty())
    {
        const Node* node = node_queue.front();
        node_queue.pop();

        if (node->left != nullptr)
        {
            node_queue.push(node->left);
        }
        if (node->right != nullptr)
        {
            node_queue.push(node->right);
        }

        if (!node_queue.empty())
        {
            const Node* right_node = node_queue.front();
            node_queue.pop();
            right_siblings.push_back(std::make_pair(node, right_node));
        }
        else
        {
            right_siblings.push_back(std::make_pair(node, nullptr));
        }
    }
    return right_siblings;
}
}  // namespace argoai
