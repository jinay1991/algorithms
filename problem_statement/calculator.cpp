///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/calculator.h"

#include <stack>
#include <string>

namespace problem_statement
{
namespace
{
constexpr std::int32_t GetOperatorPrecedence(const char op)
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

double calculate(const std::string& expression)
{
    std::stack<double> operand_stack{};
    std::stack<char> operator_stack{};
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
            double value = 0.0;
            while (std::isdigit(expression[i]) && i < expression.length())
            {
                value = (value * 10.0) + static_cast<double>(expression[i] - '0');
                i++;
            }

            operand_stack.push(value);
            i--;
        }
        else if (expression[i] == ')')
        {
            while (!operator_stack.empty() && operator_stack.top() != '(')
            {
                const double value_2 = operand_stack.top();
                operand_stack.pop();

                const double value_1 = operand_stack.top();
                operand_stack.pop();

                const char op = operator_stack.top();
                operator_stack.pop();

                const double result = Evaluate(value_1, value_2, op);
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
                   GetOperatorPrecedence(operator_stack.top()) >= GetOperatorPrecedence(expression[i]))
            {
                const double value_2 = operand_stack.top();
                operand_stack.pop();

                const double value_1 = operand_stack.top();
                operand_stack.pop();

                const char op = operator_stack.top();
                operator_stack.pop();

                const double result = Evaluate(value_1, value_2, op);
                operand_stack.push(result);
            }

            operator_stack.push(expression[i]);
        }
    }
    while (!operator_stack.empty())
    {
        const double value_2 = operand_stack.top();
        operand_stack.pop();

        const double value_1 = operand_stack.top();
        operand_stack.pop();

        const char op = operator_stack.top();
        operator_stack.pop();

        const double result = Evaluate(value_1, value_2, op);
        operand_stack.push(result);
    }
    return operand_stack.top();
}

}  // namespace problem_statement
