///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_TREE_NODE_H
#define ALGORITHMS_TREE_NODE_H

#include <sstream>
#include <string>

namespace tree
{

template <typename T>
class Node
{
  public:
    using value_type = T;

    explicit Node(const value_type data, Node* left, Node* right) : data_{data}, left_{left}, right_{right} {}

    std::string Inorder() const { return Inorder(this); }
    std::string Preorder() const { return Preorder(this); }
    std::string Postorder() const { return Postorder(this); }

  private:
    std::string Inorder(const Node* root) const
    {
        std::stringstream result{};
        if (root != nullptr)
        {
            result << Inorder(root->left_);
            result << root->data_ << ' ';
            result << Inorder(root->right_);
        }
        return result.str();
    }

    std::string Postorder(const Node* root) const
    {
        std::stringstream result{};
        if (root != nullptr)
        {
            result << Postorder(root->left_);
            result << Postorder(root->right_);
            result << root->data_ << ' ';
        }
        return result.str();
    }

    std::string Preorder(const Node* root) const
    {
        std::stringstream result{};
        if (root != nullptr)
        {
            result << root->data_ << ' ';
            result << Preorder(root->left_);
            result << Preorder(root->right_);
        }
        return result.str();
    }

    value_type data_;
    Node<value_type>* left_;
    Node<value_type>* right_;
};
}  // namespace tree

#endif  /// ALGORITHMS_TREE_NODE_H
