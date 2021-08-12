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

std::vector<std::pair<const Node*, const Node*>> find_right_siblings(const Node& root)
{
    std::vector<std::pair<const Node*, const Node*>> right_siblings{};
    std::queue<const Node*> queue;
    queue.push(&root);

    while (!queue.empty())
    {
        const auto total_nodes = queue.size();
        for (auto i = 0UL; i < total_nodes; ++i)
        {
            const auto node = queue.front();
            queue.pop();

            if (i < total_nodes - 1UL)
            {
                const auto sibling_node = queue.front();

                right_siblings.push_back(std::make_pair(node, sibling_node));
            }
            else
            {
                right_siblings.push_back(std::make_pair(node, nullptr));
            }

            if (node->left)
            {
                queue.push(node->left);
            }
            if (node->right)
            {
                queue.push(node->right);
            }
        }
    }

    return right_siblings;
}
}  // namespace problem_statement
