///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_TREE_BINARY_TREE_H
#define ALGORITHMS_TREE_BINARY_TREE_H

#include <algorithm>
#include <array>
#include <cstdint>
#include <ostream>
#include <sstream>
#include <string>

namespace tree
{

template <typename T, std::size_t kMaxNumberOfNodes, bool kIsBinarySearchTree = false>
class Tree
{
  public:
    using value_type = T;
    using index_type = std::size_t;
    using size_type = std::size_t;
    using container = std::array<value_type, kMaxNumberOfNodes>;

    constexpr Tree() : invalid_value_{}, size_{0UL}, buffer_{} { buffer_.fill(invalid_value_); }
    constexpr explicit Tree(const value_type& invalid_value) : invalid_value_{invalid_value}, size_{0UL}, buffer_{}
    {
        buffer_.fill(invalid_value_);
    }

    constexpr void Insert(const value_type& value)
    {
        if (!IsFull())
        {
            if (kIsBinarySearchTree)
            {
                InsertBST(GetRootIndex(), value);
            }
            else
            {
                InsertBT(GetRootIndex(), value);
            }
        }
    }

    constexpr void Remove(const value_type& value)
    {
        if (!IsEmpty())
        {
            const auto it = std::find(buffer_.begin(), buffer_.end(), value);
            if (it != buffer_.end())
            {
                const index_type remove_index = std::distance(buffer_.begin(), it);
                SetNodeValue(remove_index, GetInvalidValue());
                size_--;
            }
        }
    }

    constexpr size_type GetSize() const { return size_; }
    constexpr size_type GetCapacity() const { return buffer_.size(); }

    std::string GetInOrderTraversal() const { return InOrder(GetRootIndex()); }
    std::string GetPostOrderTraversal() const { return PostOrder(GetRootIndex()); }
    std::string GetPreOrderTraversal() const { return PreOrder(GetRootIndex()); }

    constexpr size_type GetMaxDepth() const { return MaxDepth(GetRootIndex()); }
    constexpr size_type GetMinValue() const { return MinValue(GetRootIndex()); }
    constexpr size_type GetMaxValue() const { return MaxValue(GetRootIndex()); }
    constexpr bool IsBinarySearchTree() const { return IsBinarySearchTree(GetRootIndex()); }

  private:
    static constexpr index_type kRootIndex = 0UL;

    constexpr index_type GetRootIndex() const { return kRootIndex; }
    constexpr index_type GetNodeIndex() const { return (GetSize() - 1UL); }
    constexpr index_type GetLeftNodeIndex(const index_type index) const { return (index * 2UL) + 1UL; }
    constexpr index_type GetRightNodeIndex(const index_type index) const { return (index * 2UL) + 2UL; }
    constexpr index_type GetParentNodeIndex(const index_type index) const { return ((index - 1UL) / 2UL); }

    constexpr bool IsEmpty() const { return (0UL == GetSize()); }
    constexpr bool IsFull() const { return (GetSize() >= GetCapacity()); }

    constexpr bool IsIndexValid(const index_type index) const { return (index < GetSize()); }

    constexpr bool HasLeftNode(const index_type index) const { return (GetLeftNodeIndex(index) < GetSize()); }
    constexpr bool HasRightNode(const index_type index) const { return (GetRightNodeIndex(index) < GetSize()); }

    constexpr value_type GetInvalidValue() const { return invalid_value_; }

    constexpr value_type GetNodeValue(const index_type index) const { return buffer_.at(index); }
    constexpr value_type GetLeftNodeValue(const index_type index) const { return GetNodeValue(GetLeftNodeIndex()); }
    constexpr value_type GetRightNodeValue(const index_type index) const { return GetNodeValue(GetRightNodeIndex()); }
    constexpr index_type GetParentNodeValue(const index_type index) const { return GetNodeValue(GetParentNodeIndex()); }

    constexpr void SetNodeValue(const index_type index, const value_type& value) { buffer_.at(index) = value; }
    constexpr void SetLeftNodeValue(const index_type index, const value_type& value)
    {
        SetNodeValue(GetLeftNodeIndex(index), value);
    }
    constexpr void SetRightNodeValue(const index_type index, const value_type& value)
    {
        SetNodeValue(GetRightNodeIndex(index), value);
    }

    constexpr index_type InsertBST(const index_type index, const value_type value)
    {
        index_type current_index = index;
        if (!IsIndexValid(current_index))
        {
            SetNodeValue(current_index, value);
            size_++;
            return current_index;
        }

        if (value > GetNodeValue(current_index))
        {
            current_index = InsertBST(GetRightNodeIndex(current_index), value);
            SetRightNodeValue(current_index, value);
            size_++;
        }
        else
        {
            current_index = InsertBST(GetLeftNodeIndex(current_index), value);
            SetLeftNodeValue(current_index, value);
            size_++;
        }
        return current_index;
    }

    constexpr index_type InsertBT(const index_type index, const value_type value)
    {
        index_type current_index = index;
        while (IsIndexValid(current_index))
        {
            if (value > GetNodeValue(current_index))
            {
                current_index = GetRightNodeIndex(current_index);
            }
            else
            {
                current_index = GetLeftNodeIndex(current_index);
            }
        }

        SetNodeValue(current_index, value);
        size_++;
        return current_index;
    }

    std::string InOrder(const index_type index) const
    {
        std::stringstream stream;
        if (IsIndexValid(index))
        {
            stream << InOrder(GetLeftNodeIndex(index)) << ", ";
            stream << GetNodeValue(index) << ", ";
            stream << InOrder(GetRightNodeIndex(index)) << ", ";
        }
        return stream.str();
    }
    std::string PostOrder(const index_type index) const
    {
        std::stringstream stream;
        if (IsIndexValid(index))
        {
            stream << PostOrder(GetLeftNodeIndex(index)) << ", ";
            stream << PostOrder(GetRightNodeIndex(index)) << ", ";
            stream << GetNodeValue(index) << ", ";
        }
        return stream.str();
    }
    std::string PreOrder(const index_type index) const
    {
        std::stringstream stream;
        if (IsIndexValid(index))
        {
            stream << GetNodeValue(index) << ", ";
            stream << PreOrder(GetLeftNodeIndex(index)) << ", ";
            stream << PreOrder(GetRightNodeIndex(index)) << ", ";
        }
        return stream.str();
    }
    constexpr size_type MaxDepth(const index_type index) const
    {
        size_type max_depth = 0UL;
        if (IsIndexValid(index))
        {
            const size_type left_depth = MaxDepth(GetLeftNodeIndex(index));
            const size_type right_depth = MaxDepth(GetRightNodeIndex(index));

            max_depth = std::max(left_depth + 1UL, right_depth + 1UL);
        }
        return max_depth;
    }
    constexpr value_type MinValue(const index_type index) const
    {
        index_type current_index = index;
        while (HasLeftNode(current_index))
        {
            current_index = GetLeftNodeIndex(current_index);
        }
        return GetNodeValue(current_index);
    }
    constexpr value_type MaxValue(const index_type index) const
    {
        index_type current_index = index;
        while (HasRightNode(current_index))
        {
            current_index = GetRightNodeIndex(current_index);
        }
        return GetNodeValue(current_index);
    }

    constexpr bool IsBinarySearchTree(const index_type index) const
    {
        bool is_binary_search_tree = true;
        if (IsIndexValid(index))
        {
            if (GetLeftNodeIndex(index) && (MaxValue(GetLeftNodeIndex(index)) > GetNodeValue(index)))
            {
                is_binary_search_tree = false;
            }
            else if (GetRightNodeIndex(index) && (MinValue(GetRightNodeIndex(index)) <= GetNodeValue(index)))
            {
                is_binary_search_tree = false;
            }
            else if ((!IsBinarySearchTree(GetLeftNodeIndex(index))) || (!IsBinarySearchTree(GetRightNodeIndex(index))))
            {
                is_binary_search_tree = false;
            }
            else
            {
                // do nothing
            }
        }
        return is_binary_search_tree;
    }

    const value_type invalid_value_;
    size_type size_;
    container buffer_;
};

}  // namespace tree

#endif  /// ALGORITHMS_TREE_BINARY_TREE_H
