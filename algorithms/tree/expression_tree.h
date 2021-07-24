///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_TREE_EXPRESSION_TREE_H
#define ALGORITHMS_TREE_EXPRESSION_TREE_H

#include "algorithms/tree/node.h"

#include <cstdint>
#include <iostream>
#include <memory>
#include <sstream>
#include <stack>
#include <string>

namespace tree
{
namespace
{

constexpr std::int32_t GetOperatorPrecedence(const char op) noexcept
{
    std::int32_t precedence = 0;
    switch (op)
    {
        case '^':
        {
            precedence = 3;
            break;
        }
        case '*':
        case '/':
        {
            precedence = 2;
            break;
        }
        case '+':
        case '-':
        {
            precedence = 1;
            break;
        }
        default:
        {
            break;
        }
    }
    return precedence;
}
}  // namespace

class ExpressionTree
{
  public:
    ExpressionTree() = default;

    ///
    /// ((1+2)*3-4*5)
    void Construct(const std::string& expression)
    {
        std::stack<char> operator_stack{};
        std::stack<Node<char>*> node_stack{};
        for (auto i = 0; i < expression.length(); ++i)
        {
            if (expression[i] == ' ')
            {
                continue;
            }
            else if (expression[i] == '(')
            {
                operator_stack.push(expression[i]);
            }
            else if (std::isdigit(expression[i]))
            {
                // while (std::isdigit(expression[i]) && i < expression.length())
                {
                    Node<char>* node = new Node<char>{expression[i], nullptr, nullptr};
                    node_stack.push(node);
                    // i++;
                }
                // i--;
            }
            else if (expression[i] == ')')
            {
                while (!operator_stack.empty() && operator_stack.top() != '(')
                {
                    auto node_2 = node_stack.top();
                    node_stack.pop();

                    auto node_1 = node_stack.top();
                    node_stack.pop();

                    const auto op = operator_stack.top();
                    operator_stack.pop();

                    Node<char>* node = new Node<char>{op, node_1, node_2};
                    node_stack.push(node);
                }

                if (!operator_stack.empty())
                {
                    operator_stack.pop();  // discard '('
                }
            }
            else
            {
                while (!operator_stack.empty() &&
                       ((expression[i] != '^' &&
                         GetOperatorPrecedence(operator_stack.top()) >= GetOperatorPrecedence(expression[i])) ||
                        (expression[i] == '^' &&
                         GetOperatorPrecedence(operator_stack.top()) > GetOperatorPrecedence(expression[i]))))
                {
                    auto node_2 = node_stack.top();
                    node_stack.pop();

                    auto node_1 = node_stack.top();
                    node_stack.pop();

                    const auto op = operator_stack.top();
                    operator_stack.pop();

                    Node<char>* node = new Node<char>{op, node_1, node_2};
                    node_stack.push(node);
                }

                operator_stack.push(expression[i]);
            }
        }
        while (!operator_stack.empty())
        {
            auto node_2 = node_stack.top();
            node_stack.pop();

            auto node_1 = node_stack.top();
            node_stack.pop();

            const auto op = operator_stack.top();
            operator_stack.pop();

            Node<char>* node = new Node<char>{op, node_1, node_2};
            node_stack.push(node);
        }

        root_ = node_stack.top();
    }

    std::string GetInfixExpression() const { return root_->Inorder(); }
    std::string GetPostfixExpression() const { return root_->Postorder(); }
    std::string GetPrefixExpression() const { return root_->Preorder(); }

  private:
    Node<char>* root_;
};

}  // namespace tree

#endif  // ALGORITHMS_TREE_EXPRESSION_TREE_H
