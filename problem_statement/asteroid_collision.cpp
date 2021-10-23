///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/asteroid_collision.h"

#include <algorithm>
#include <stack>

namespace problem_statement
{

std::vector<std::int32_t> AsteroidCollision(const std::vector<std::int32_t>& asteroids)
{
    std::stack<int> stack{};
    for (auto& asteroid : asteroids)
    {
        if (asteroid > 0)
        {
            stack.push(asteroid);
        }
        else
        {
            while (!stack.empty() && stack.top() > 0 && stack.top() < std::abs(asteroid))
            {
                stack.pop();
            }
            if (stack.empty() || stack.top() < 0)
            {
                stack.push(asteroid);
            }
            else if (stack.top() == std::abs(asteroid))
            {
                stack.pop();
            }
        }
    }

    std::vector<int> result;
    while (!stack.empty())
    {
        const auto asteroid = stack.top();
        stack.pop();
        result.push_back(asteroid);
    }
    std::reverse(result.begin(), result.end());
    return result;
}

}  // namespace problem_statement
