///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef DATATYPES_TREE_H
#define DATATYPES_TREE_H

#include <cstdint>
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
                            const Node* parent = nullptr,
                            const Node* left = nullptr,
                            const Node* right = nullptr) noexcept
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

    constexpr const T& GetValue() const { return value_; }
    constexpr void SetValue(const T& value) { value_ = value; }

    constexpr const Node* GetParentNode() const { return parent_; }
    constexpr const Node* GetLeftNode() const { return left_; }
    constexpr const Node* GetRightNode() const { return right_; }

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
    Tree() : root_{}, size_{0U}, width_{0U}, height_{0U} {}

    void Insert(const T& value)
    {
        if (!IsRootNodeExist())
        {
            root_.SetValue(value);
            size_++;
            width_++;
            height_++;
        }
        else
        {
        }
    }

    void Remove(const T& value) {}
    void Search(const T& value) {}

    constexpr std::size_t GetSize() const { return size_; }
    constexpr std::size_t GetWidth() const { return width_; }
    constexpr std::size_t GetHeight() const { return height_; }
    constexpr bool Contains(const T& value) const { return true; }

  private:
    constexpr bool IsRootNodeExist() const { return root_.IsRootNode(); }

    Node<T> root_;
    std::size_t size_;
    std::size_t width_;
    std::size_t height_;
};

}  // namespace datatypes

#endif  /// DATATYPES_TREE_H