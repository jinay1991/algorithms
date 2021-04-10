///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef DATATYPES_TREE_H
#define DATATYPES_TREE_H

#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace datatypes
{
namespace
{
template <typename T>
class Node
{
  public:
    constexpr Node() : value_{}, parent_{nullptr}, left_{nullptr}, right_{nullptr} {}

    constexpr explicit Node(const T& value,
                            Node* parent = nullptr,
                            Node* left = nullptr,
                            Node* right = nullptr) noexcept
        : value_{value}, parent_{parent}, left_{left}, right_{right}
    {
    }

    constexpr explicit Node(const Node& other) noexcept
        : value_{other.value_}, parent_{other.parent_}, left_{other.left_}, right_{other.right_}
    {
    }

    constexpr Node& operator=(const Node& other) noexcept
    {
        value_ = other.GetValue();
        parent_ = other.GetParentNode();
        left_ = other.GetLeftNode();
        right_ = other.GetRightNode();
    }

    constexpr explicit Node(Node&& other) = delete;
    constexpr Node& operator=(Node&& other) = delete;

    constexpr void SetValue(const T& value) { value_ = value; }
    constexpr void SetParentNode(Node* parent) { parent_ = parent; }
    constexpr void SetLeftNode(Node* left) { left_ = left; }
    constexpr void SetRightNode(Node* right) { right_ = right; }

    constexpr const T& GetValue() const { return value_; }
    constexpr Node* GetParentNode() const { return parent_; }
    constexpr Node* GetLeftNode() const { return left_; }
    constexpr Node* GetRightNode() const { return right_; }

    constexpr bool HasParentNode() const { return (parent_ != nullptr); }
    constexpr bool HasLeftNode() const { return (left_ != nullptr); }
    constexpr bool HasRightNode() const { return (right_ != nullptr); }

    constexpr bool IsRootNode() const { return (!HasParentNode()); }

  private:
    T value_;

    Node* parent_;
    Node* left_;
    Node* right_;
};
}  // namespace

template <typename T>
class Tree
{
  public:
    constexpr Tree() : root_{nullptr}, size_{0U}, width_{0U}, height_{0U} {}
    ~Tree() = default;

    constexpr void Insert(const std::vector<std::int32_t>& list)
    {
        for (const auto& value : list)
        {
            Insert(value);
        }
    }

    constexpr void Insert(const T& value)
    {
        Node<T>* new_node = CreateNode(value);
        if (!IsRootNodeExist())
        {
            root_ = new_node;
        }
        else
        {
            Node<T>* node = root_;
            while (node)
            {
                if (node->GetValue() < value)
                {
                    if (!node->HasLeftNode())
                    {
                        new_node->SetParentNode(node);
                        node->SetLeftNode(new_node);
                        break;
                    }
                    node = node->GetLeftNode();
                }
                if (node->GetValue() > value)
                {
                    if (!node->HasRightNode())
                    {
                        new_node->SetParentNode(node);
                        node->SetRightNode(new_node);
                        break;
                    }
                    node = node->GetRightNode();
                }
            }
        }
    }

    constexpr void Remove(const T& value) {}
    constexpr void Search(const T& value) {}

    constexpr std::size_t GetSize() const { return size_; }
    constexpr std::size_t GetWidth() const { return width_; }
    constexpr std::size_t GetHeight() const { return height_; }
    constexpr bool Contains(const T& value) const { return true; }

    std::string ToString() const { return ToString(root_); }

  private:
    constexpr Node<T>* CreateNode(const T& value)
    {
        size_++;
        height_++;
        width_++;
        return (new Node<T>{value});
    }
    constexpr bool IsRootNodeExist() const { return (root_ != nullptr); }

    std::string ToString(const Node<T>* node, const std::string prefix = "", const bool is_left = false) const
    {
        std::stringstream stream{};
        if (node)
        {
            stream << prefix;

            stream << (is_left ? "├──" : "└──");

            stream << " " << node->GetValue() << std::endl;

            stream << ToString(node->GetLeftNode(), prefix + (is_left ? "│   " : "    "), true);
            stream << ToString(node->GetRightNode(), prefix + (is_left ? "│   " : "    "), false);
        }
        return stream.str();
    }

    Node<T>* root_;
    std::size_t size_;
    std::size_t width_;
    std::size_t height_;
};

template <typename T>
inline std::ostream& operator<<(std::ostream& out, const Tree<T>& tree) noexcept
{
    out << tree.ToString();
    return out;
}

}  // namespace datatypes

#endif  /// DATATYPES_TREE_H