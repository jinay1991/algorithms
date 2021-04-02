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
    std::vector<std::pair<const Node*, const Node*>> result;
    std::queue<const Node*> node_queue;

    node_queue.push(&root);

    while (!node_queue.empty())
    {
        const Node* node = node_queue.front();
        std::cout << node->id << " ";
        node_queue.pop();

        if (node->left != nullptr)
        {
            node_queue.push(node->left);
        }
        if (node->right != nullptr)
        {
            node_queue.push(node->right);
        }
    }
    std::cout << std::endl;

    return result;
}
}  // namespace argoai
