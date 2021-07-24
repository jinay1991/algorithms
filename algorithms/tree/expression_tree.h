///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_TREE_EXPRESSION_TREE_H
#define ALGORITHMS_TREE_EXPRESSION_TREE_H
#include <stack>
#include <string>

namespace tree
{
template <typename T>
class Tree
{
  public:
    using value_type = T;

    Tree() : value_{}, left_{}, right_{} {}
    explicit Tree(const value_type& value) : value_{value}, left_{}, right_{} {}

    value_type value_;
    Tree<value_type> left_;
    Tree<value_type> right_;
};

constexpr double Evaluate(const double value_1, const double value_2, const char op) {}

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
            double value = 0;
            while (std::isdigit(expression[i]) && (i < expression.length()))
            {
                value = (value * 10.0) + static_cast<double>(expression[i] - '0');
                i++;
            }

            operand_stack.push(value);
            i--;
        }
        else if (expression[i] == ')')
        {
            while (!operator_stack.empty() && operator_stack.top() != ')')
            {
                const double value_2 = operand_stack.top();
                operand_stack.pop();

                const double value_1 = operand_stack.top();
                operand_stack.pop();

                const double result = Evaluate(value_1, value_2, expression[i]);
                operand_stack.push(result);
            }
        }
        else
        {
            while (!operator_stack.empty() && Precedence(operator_stack.top()) > Precedence(expression[i]))
            {
                const double value_2 = operand_stack.top();
                operand_stack.pop();

                const double value_1 = operand_stack.top();
                operand_stack.pop();

                const double result = Evaluate(value_1, value_2, expression[i]);
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

}  // namespace tree

#endif  /// ALGORITHMS_TREE_EXPRESSION_TREE_H
