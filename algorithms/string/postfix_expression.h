///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_STRING_POSTFIX_EXPRESSION_H
#define ALGORITHMS_STRING_POSTFIX_EXPRESSION_H

#include <queue>
#include <stack>
#include <string>

namespace string
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

/// @brief Convert infix expression to postfix expression
/// @note Shunting-yard algorithm
/// @param expression[in] - Infix Expression (string)
/// @return Postfix Expression (string)
std::string ToPostfix(const std::string& expression)
{
    std::stack<char> operator_stack{};
    std::queue<char> output_queue{};
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
            while (std::isdigit(expression[i]) && i < expression.length())
            {
                output_queue.push(expression[i]);
                i++;
            }
            output_queue.push(' ');
            i--;
        }
        else if (expression[i] == ')')
        {
            while (!operator_stack.empty() && operator_stack.top() != '(')
            {
                const char op = operator_stack.top();
                operator_stack.pop();

                output_queue.push(op);
                output_queue.push(' ');
            }

            if (!operator_stack.empty())
            {
                operator_stack.pop();  // pop '(' -> discarded
            }
        }
        else
        {
            while (!operator_stack.empty() &&
                   GetOperatorPrecedence(operator_stack.top()) >= GetOperatorPrecedence(expression[i]))
            {
                const char op = operator_stack.top();
                operator_stack.pop();

                output_queue.push(op);
                output_queue.push(' ');
            }

            operator_stack.push(expression[i]);
        }
    }
    while (!operator_stack.empty())
    {
        const char op = operator_stack.top();
        operator_stack.pop();

        output_queue.push(op);
    }

    std::string postfix_expression{};
    while (!output_queue.empty())
    {
        postfix_expression += output_queue.front();
        output_queue.pop();
    }

    return postfix_expression;
}

}  // namespace string

#endif  /// ALGORITHMS_STRING_POSTFIX_EXPRESSION_H
