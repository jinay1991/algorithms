///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/find_right_sibling.h"

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

namespace problem_statement
{
/// @brief Given the root of a binary tree, return all of the right-sibling pairs.
/// If a node has no right sibling, the second element of its pair should be null
std::vector<std::pair<const Node*, const Node*>> find_right_siblings(const Node& root)
{
    std::vector<std::vector<const Node*>> siblings;
    std::vector<const Node*> level_siblings;
    std::queue<const Node*> queue;
    queue.push(&root);
    queue.push(nullptr);

    level_siblings.push_back(&root);
    siblings.push_back(level_siblings);
    level_siblings.clear();

    while (queue.size() > 1)
    {
        const Node* node = queue.front();
        queue.pop();

        if (node == nullptr)
        {
            queue.push(nullptr);
            siblings.push_back(level_siblings);
            level_siblings.clear();
            continue;
        }

        if (node->left)
        {
            queue.push(node->left);
            level_siblings.push_back(node->left);
        }
        if (node->right)
        {
            queue.push(node->right);
            level_siblings.push_back(node->right);
        }
    }
    for (const auto& level_sibling : siblings)
    {
        for (const auto& node : level_sibling)
        {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }
    return std::vector<std::pair<const Node*, const Node*>>{};
}
}  // namespace problem_statement
