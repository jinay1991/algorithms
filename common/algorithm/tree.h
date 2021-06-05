///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef COMMON_ALGORITHM_TREE_H
#define COMMON_ALGORITHM_TREE_H

#include <algorithm>
#include <cstdint>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

namespace algorithm
{
namespace
{
template <typename T>
class Node
{
  public:
    constexpr explicit Node(const T& value,
                            Node<T>* parent = nullptr,
                            Node<T>* left = nullptr,
                            Node<T>* right = nullptr)
        : value_{value}, parent_{parent}, left_{left}, right_{right}
    {
    }

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

    constexpr void CreateLeftNode(const T& value, Node<T>* parent = nullptr) { left_ = new Node<T>(value, parent); }
    constexpr void CreateRightNode(const T& value, Node<T>* parent = nullptr) { right_ = new Node<T>(value, parent); }

    constexpr const T& GetValue() const { return value_; }

    constexpr Node<T>* GetParentNode() const { return parent_; }
    constexpr Node<T>* GetLeftNode() const { return left_; }
    constexpr Node<T>* GetRightNode() const { return right_; }

    constexpr bool HasParentNode() const { return (parent_ != nullptr); }
    constexpr bool HasLeftNode() const { return (left_ != nullptr); }
    constexpr bool HasRightNode() const { return (right_ != nullptr); }

    constexpr bool IsRootNode() const { return (!HasParentNode()); }

  private:
    T value_;

    Node<T>* parent_;
    Node<T>* left_;
    Node<T>* right_;
};
}  // namespace

template <typename T>
class Tree
{
  public:
    Tree() : root_{nullptr}, size_{0U} {}
    ~Tree()
    {
        if (root_)
        {
            size_--;
            delete root_;
        }
    }

    void Insert(const std::vector<T>& list)
    {
        std::for_each(list.cbegin(), list.cend(), [&](const auto& value) { Insert(value); });
    }

    void Insert(const T& value)
    {
        if (root_ == nullptr)
        {
            size_++;
            root_ = new Node<T>(value);
        }
        else
        {  // root exists
            Node<T>* current_node = root_;
            while (current_node)
            {
                if (value <= current_node->GetValue())
                {
                    if (current_node->HasLeftNode())
                    {
                        current_node = current_node->GetLeftNode();
                    }
                    else
                    {
                        size_++;
                        current_node->CreateLeftNode(value);
                        break;
                    }
                }
                else if (value > current_node->GetValue())
                {
                    if (current_node->HasRightNode())
                    {
                        current_node = current_node->GetRightNode();
                    }
                    else
                    {
                        size_++;
                        current_node->CreateRightNode(value);
                        break;
                    }
                }
            }
        }
    }

    constexpr std::size_t GetSize() const { return size_; }

    std::string ToString() const noexcept { return ToString(root_); }

  private:
    std::string ToString(const Node<T>* root, const std::string prefix = "", const bool is_left = false) const noexcept
    {
        std::stringstream sstream;
        if (root)
        {
            sstream << prefix;
            sstream << (is_left ? "├──" : "└──");
            sstream << " " << root->GetValue() << std::endl;

            sstream << ToString(root->GetLeftNode(), prefix + (is_left ? "│   " : "    "), true);
            sstream << ToString(root->GetRightNode(), prefix + (is_left ? "│   " : "    "), false);
        }
        return sstream.str();
    }

    Node<T>* root_;
    std::size_t size_;
};

template <typename T>
inline std::ostream& operator<<(std::ostream& out, const Tree<T>& tree) noexcept
{
    out << tree.ToString();
    return out;
}

}  // namespace algorithm

#endif  /// COMMON_ALGORITHM_TREE_H
