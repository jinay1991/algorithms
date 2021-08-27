///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_TREE_EXPRESSION_TREE_H
#define ALGORITHMS_TREE_EXPRESSION_TREE_H

#include "algorithms/tree/node.h"

#include <string>

namespace tree
{

class ExpressionTree
{
  public:
    void Construct(const std::string& expression);
    double EvaluateExpression() const;

    std::string GetInfixExpression() const;
    std::string GetPostfixExpression() const;
    std::string GetPrefixExpression() const;

  private:
    Node<char>* root_;
};

}  // namespace tree

#endif  // ALGORITHMS_TREE_EXPRESSION_TREE_H
