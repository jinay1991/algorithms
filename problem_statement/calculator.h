///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef PROBLEM_STATEMENT_CALCULATOR_H
#define PROBLEM_STATEMENT_CALCULATOR_H

#include <string>

namespace problem_statement
{

/// @brief Evaluate result of given expression.
///
/// @param expression[in] - Expression to be evaluated
/// @return Result of expression evaluation
double calculate(const std::string& input);

}  // namespace problem_statement

#endif  /// PROBLEM_STATEMENT_CALCULATOR_H
