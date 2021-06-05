///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef COMMON_ALGORITHM_EXPR_TREE_H
#define COMMON_ALGORITHM_EXPR_TREE_H

#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

namespace algorithm
{
namespace
{
template <typename T>
class Node
{
  public:
    inline explicit Node(const T& value) : value_{value}, left_{nullptr}, right_{nullptr} {}

    ~Node()
    {
        if (left_)
        {
            delete left_;
        }
        if (right_)
        {
            delete right_;
        }
    }

    inline const T& GetValue() const { return value_; }
    inline Node<T>* GetLeftNode() const { return left_; }
    inline Node<T>* GetRightNode() const { return right_; }

    inline void SetLeftNode(Node<T>* left) { left_ = left; }
    inline void SetRightNode(Node<T>* right) { right_ = right; }

  private:
    T value_;

    Node<T>* left_;
    Node<T>* right_;
};
}  // namespace

class ExprTree
{
  public:
    ExprTree() : root_{}, size_{0U}, stack_{} {}

    void Insert(const std::string& expression)
    {
        std::stringstream sstream{expression};
        char token;
        while (sstream >> token)
        {
            if (IsOperator(token))
            {
                Node<std::string>* a = stack_.top();
                stack_.pop();

                Node<std::string>* b = stack_.top();
                stack_.pop();

                Node<std::string>* node = new Node<std::string>(std::to_string(token));
                node->SetLeftNode(a);
                node->SetRightNode(b);
                size_++;
            }
            else
            {
                sstream.putback(token);
                double value = 0.0;
                sstream >> value;
                Node<std::string>* node = new Node<std::string>(std::to_string(value));
                stack_.push(node);
                size_++;
            }
        }
        root_ = stack_.top();
        stack_.pop();
    }

    constexpr std::size_t GetSize() const noexcept { return size_; }

  private:
    constexpr bool IsOperator(const char ch) const noexcept
    {
        return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
    }

    Node<std::string>* root_;
    std::size_t size_;
    std::stack<Node<std::string>*> stack_;
};
}  // namespace algorithm

#endif  /// COMMON_ALGORITHM_EXPR_TREE_H
