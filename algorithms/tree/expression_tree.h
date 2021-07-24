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
constexpr double Evaluate(const double value_1, const double value_2, const char op)
{
    double result = 0.0;
    switch (op)
    {
        case '*':
        {
            result = value_1 * value_2;
            break;
        }
        case '/':
        {
            result = value_1 / value_2;
            break;
        }
        case '+':
        {
            result = value_1 + value_2;
            break;
        }
        case '-':
        {
            result = value_1 - value_2;
            break;
        }
        default:
        {
            break;
        }
    }
    return result;
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

    double EvaluateExpression() const
    {
        std::stack<double> operand_stack{};
        std::stack<char> operator_stack{};

        const std::string postfix_expression = GetPostfixExpression();
        for (auto i = 0; i < postfix_expression.length(); ++i)
        {
            if (postfix_expression[i] == ' ')
            {
                continue;
            }
            else if (postfix_expression[i] == '(')
            {
                operator_stack.push(postfix_expression[i]);
            }
            else if (std::isdigit(postfix_expression[i]))
            {
                double value = 0.0;
                while (std::isdigit(postfix_expression[i]) && i < postfix_expression.length())
                {
                    value = (value * 10.0) + static_cast<double>(postfix_expression[i] - '0');
                    i++;
                }

                operand_stack.push(value);
                i--;
            }
            else if (postfix_expression[i] == ')')
            {
                while (!operator_stack.empty() && operator_stack.top() != '(')
                {
                    const auto value_2 = operand_stack.top();
                    operand_stack.pop();

                    const auto value_1 = operand_stack.top();
                    operand_stack.pop();

                    const auto op = operator_stack.top();
                    operator_stack.pop();

                    const auto result = Evaluate(value_1, value_2, op);
                    operand_stack.push(result);
                }

                if (!operator_stack.empty())
                {
                    operator_stack.pop();
                }
            }
            else
            {
                while (!operator_stack.empty() &&
                       GetOperatorPrecedence(operator_stack.top()) >= GetOperatorPrecedence(postfix_expression[i]))
                {
                    const auto value_2 = operand_stack.top();
                    operand_stack.pop();

                    const auto value_1 = operand_stack.top();
                    operand_stack.pop();

                    const auto op = operator_stack.top();
                    operator_stack.pop();

                    const auto result = Evaluate(value_1, value_2, op);
                    operand_stack.push(result);
                }
                operator_stack.push(postfix_expression[i]);
            }
        }
        while (!operator_stack.empty())
        {
            const auto value_2 = operand_stack.top();
            operand_stack.pop();

            const auto value_1 = operand_stack.top();
            operand_stack.pop();

            const auto op = operator_stack.top();
            operator_stack.pop();

            const auto result = Evaluate(value_1, value_2, op);
            operand_stack.push(result);
        }

        return operand_stack.top();
    }

    std::string GetInfixExpression() const { return root_->Inorder(); }
    std::string GetPostfixExpression() const { return root_->Postorder(); }
    std::string GetPrefixExpression() const { return root_->Preorder(); }

  private:
    Node<char>* root_;
};

}  // namespace tree

#endif  // ALGORITHMS_TREE_EXPRESSION_TREE_H
