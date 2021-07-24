///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_TREE_MAX_HEAP_H
#define ALGORITHMS_TREE_MAX_HEAP_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <sstream>

namespace tree
{

template <typename T, std::size_t kMaxNumberOfNodes>
class MaxHeap
{
  public:
    using value_type = T;
    using index_type = std::size_t;
    using size_type = std::size_t;
    using container = std::array<value_type, kMaxNumberOfNodes>;
    using reference = typename container::reference;
    using const_reference = typename container::const_reference;

    static constexpr size_type kMaxDepth = ((kMaxNumberOfNodes - 1UL) / 2UL);
    static constexpr index_type kRootIndex = 0U;

    constexpr MaxHeap() : size_{0UL}, buffer_{} {}

    constexpr MaxHeap(const std::initializer_list<value_type>& list) : size_{0UL}, buffer_{}
    {
        for (auto& value : list)
        {
            Push(value);
        }
    }

    constexpr void Push(const value_type& value)
    {
        if (IsFull())
        {
            std::cerr << "No space left for inserting new element to the buffer!" << std::endl;
            return;
        }

        size_++;
        SetCurrentNodeValue(value);

        HeapifyUp();
    }

    constexpr value_type Pop()
    {
        if (IsEmpty())
        {
            std::cerr << "Nothing in the buffer!" << std::endl;
            return value_type{};
        }
        const value_type largest_node_value = GetNodeValue(kRootIndex);
        Swap(kRootIndex, GetCurrentNodeIndex());
        size_--;

        HeapifyDown();

        return largest_node_value;
    }

    constexpr void Reset()
    {
        buffer_.fill(value_type{});
        size_ = 0UL;
    }

    constexpr value_type GetMaxNodeValue() const { return GetNodeValue(kRootIndex); }
    constexpr value_type GetNodeValue(const index_type node_index) const { return buffer_.at(node_index); }

    constexpr size_type GetCapacity() const { return buffer_.size(); }
    constexpr size_type GetSize() const { return size_; }
    constexpr size_type GetDepth() const
    {
        return static_cast<size_type>(std::ceil((static_cast<double>(GetSize()) - 1.0) / 2.0));
    }

    constexpr bool IsEmpty() const { return (0UL == GetSize()); }
    constexpr bool IsFull() const { return (GetSize() >= GetCapacity()); }

    constexpr std::array<value_type, kMaxDepth> GetLeftView() const
    {
        std::array<value_type, kMaxDepth> left_view{};
        index_type current_node_index = 0UL;
        index_type left_view_index = 0UL;
        left_view.at(left_view_index) = GetNodeValue(current_node_index);
        left_view_index++;
        while (current_node_index <= GetSize())
        {
            const index_type left_node_index = GetLeftNodeIndex(current_node_index);
            const value_type left_node_value = GetNodeValue(left_node_index);
            const index_type right_node_index = GetRightNodeIndex(current_node_index);
            const value_type right_node_value = GetNodeValue(right_node_index);
            if (left_node_value != 0UL)
            {
                left_view.at(left_view_index) = left_node_value;
                current_node_index = left_node_index;
            }
            else
            {
                left_view.at(left_view_index) = right_node_value;
                current_node_index = right_node_index;
            }
            left_view_index++;
        }
        return left_view;
    }

  private:
    constexpr void HeapifyUp()
    {
        index_type current_node_index = GetCurrentNodeIndex();
        while (HasParentNode(current_node_index) &&
               (GetParentNodeValue(current_node_index) < GetNodeValue(current_node_index)))
        {
            const index_type parent_node_index = GetParentNodeIndex(current_node_index);
            Swap(parent_node_index, current_node_index);
            current_node_index = parent_node_index;
        }
    }

    constexpr void HeapifyDown()
    {
        index_type current_node_index = kRootIndex;
        while (HasLeftNode(current_node_index))
        {
            index_type largest_node_index = GetLeftNodeIndex(current_node_index);
            if (HasRightNode(largest_node_index) &&
                (GetRightNodeValue(current_node_index) > GetLeftNodeValue(current_node_index)))
            {
                largest_node_index = GetRightNodeIndex(current_node_index);
            }

            if (GetNodeValue(current_node_index) > GetNodeValue(largest_node_index))
            {
                break;
            }
            else
            {
                Swap(largest_node_index, current_node_index);
            }
            current_node_index = largest_node_index;
        }
    }

    constexpr index_type GetCurrentNodeIndex() const { return (size_ - 1UL); }

    constexpr void SetCurrentNodeValue(const value_type& value) { SetNodeValue(GetCurrentNodeIndex(), value); }

    constexpr void Swap(const index_type parent_node_index, const index_type current_node_index)
    {
        const value_type parent_node_value = GetNodeValue(parent_node_index);
        const value_type current_node_value = GetNodeValue(current_node_index);
        SetNodeValue(parent_node_index, current_node_value);
        SetNodeValue(current_node_index, parent_node_value);
    }

    constexpr void SetNodeValue(const index_type node_index, const value_type& value)
    {
        buffer_.at(node_index) = value;
    }

    constexpr index_type GetLeftNodeIndex(const index_type node_index) const { return ((2UL * node_index) + 1UL); }
    constexpr index_type GetRightNodeIndex(const index_type node_index) const { return ((2UL * node_index) + 2UL); }
    constexpr index_type GetParentNodeIndex(const index_type node_index) const { return ((node_index - 1UL) / 2UL); }

    constexpr bool HasLeftNode(const index_type node_index) const { return (GetLeftNodeIndex(node_index) < GetSize()); }
    constexpr bool HasRightNode(const index_type node_index) const
    {
        return (GetRightNodeIndex(node_index) < GetSize());
    }
    constexpr bool HasParentNode(const index_type node_index) const
    {
        return (GetParentNodeIndex(node_index) < GetSize());
    }

    constexpr value_type GetLeftNodeValue(const index_type node_index) const
    {
        return GetNodeValue(GetLeftNodeIndex(node_index));
    }
    constexpr value_type GetRightNodeValue(const index_type node_index) const
    {
        return GetNodeValue(GetRightNodeIndex(node_index));
    }
    constexpr value_type GetParentNodeValue(const index_type node_index) const
    {
        return GetNodeValue(GetParentNodeIndex(node_index));
    }

    size_type size_;
    container buffer_;
};

template <typename T, std::size_t kMaxNumberOfNodes>
std::string to_string(const MaxHeap<T, kMaxNumberOfNodes>& tree)
{
    std::stringstream sstream;
    for (auto node_index = 0UL; node_index < tree.GetSize(); node_index++)
    {
        sstream << " " << tree.GetNodeValue(node_index);
    }
    return sstream.str();
}

template <typename T, std::size_t kMaxNumberOfNodes>
std::ostream& operator<<(std::ostream& stream, const MaxHeap<T, kMaxNumberOfNodes>& tree)
{
    const std::string str = to_string(tree);
    stream << str;
    return stream;
}
}  // namespace tree

#endif  /// ALGORITHMS_TREE_MAX_HEAP_H
