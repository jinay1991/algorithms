///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHMS_TREE_BINARY_TREE_H
#define ALGORITHMS_TREE_BINARY_TREE_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <list>
#include <queue>

namespace tree
{

template <typename T, std::size_t kMaxNumberOfNodes>
class Tree
{
  public:
    using value_type = T;
    using index_type = std::size_t;
    using size_type = std::size_t;
    using container = std::array<value_type, kMaxNumberOfNodes>;
    using traversal_container = std::list<value_type>;

    constexpr Tree() : invalid_value_{}, size_{0UL}, buffer_{} {}

    constexpr explicit Tree(const value_type& invalid_value) : invalid_value_{invalid_value}, size_{0UL}, buffer_{}
    {
        buffer_.fill(invalid_value_);
    }

    constexpr void Insert(const value_type& value)
    {
        if (!IsFull())
        {
            index_type current_index = GetRootIndex();
            if (IsEmpty())
            {
                // std::cout << "Inserted " << value << " to the root (idx: " << current_index
                //           << ") => size: " << (GetSize() + 1UL) << std::endl;
                SetNodeValue(current_index, value);
                size_++;
            }
            else
            {
                while (IsNodeIndexValid(current_index))
                {
                    if (value < GetNodeValue(current_index))
                    {
                        if (HasLeftNode(current_index))
                        {
                            current_index = GetLeftNodeIndex(current_index);
                        }
                        else
                        {
                            // std::cout << "Inserted " << value
                            //           << " to the left (idx: " << GetLeftNodeIndex(current_index) << ") of "
                            //           << GetNodeValue(current_index) << " (idx: " << current_index
                            //           << ") => size: " << (GetSize() + 1UL) << std::endl;
                            SetLeftNodeValue(current_index, value);
                            size_++;
                            break;
                        }
                    }
                    else if (value > GetNodeValue(current_index))
                    {
                        if (HasRightNode(current_index))
                        {
                            current_index = GetRightNodeIndex(current_index);
                        }
                        else
                        {
                            // std::cout << "Inserted " << value
                            //           << " to the right (idx: " << GetRightNodeIndex(current_index) << ") of "
                            //           << GetNodeValue(current_index) << " (idx: " << current_index
                            //           << ") => size: " << (GetSize() + 1UL) << std::endl;
                            SetRightNodeValue(current_index, value);
                            size_++;
                            break;
                        }
                    }
                }
            }
        }
    }

    constexpr void InsertFromList(const std::initializer_list<value_type>& list)
    {
        for (const auto& value : list)
        {
            Insert(value);
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

    constexpr traversal_container GetInOrderTraversal() const
    {
        traversal_container traversal{};
        InOrder(GetRootIndex(), traversal);
        return traversal;
    }

    constexpr traversal_container GetPostOrderTraversal() const
    {
        traversal_container traversal{};
        PostOrder(GetRootIndex(), traversal);
        return traversal;
    }

    constexpr traversal_container GetPreOrderTraversal() const
    {
        traversal_container traversal{};
        PreOrder(GetRootIndex(), traversal);
        return traversal;
    }

    constexpr traversal_container GetLevelOrderTraversal() const
    {
        traversal_container traversal{};
        LevelOrder(GetRootIndex(), traversal);
        return traversal;
    }

    constexpr traversal_container GetArrayIndexTraversal() const
    {
        traversal_container traversal{};
        for (auto index = 0UL; index < GetCapacity(); ++index)
        {
            traversal.push_back(GetNodeValue(index));
        }
        return traversal;
    }

    constexpr traversal_container GetLeftViewTraversal() const
    {
        traversal_container traversal{};
        SideViewTraversal(GetRootIndex(), SideView::kLeft, traversal);
        return traversal;
    }

    constexpr traversal_container GetRightViewTraversal() const
    {
        traversal_container traversal{};
        SideViewTraversal(GetRootIndex(), SideView::kRight, traversal);
        return traversal;
    }

    constexpr traversal_container GetTopViewTraversal() const
    {
        traversal_container traversal{};
        SideViewTraversal(GetRootIndex(), SideView::kTop, traversal);
        return traversal;
    }

    constexpr traversal_container GetBottomViewTraversal() const
    {
        traversal_container traversal{};
        SideViewTraversal(GetRootIndex(), SideView::kBottom, traversal);
        return traversal;
    }

    constexpr size_type GetMaxDepth() const { return MaxDepth(GetRootIndex()); }

    constexpr size_type GetMinValue() const { return MinValue(GetRootIndex()); }

    constexpr size_type GetMaxValue() const { return MaxValue(GetRootIndex()); }

    constexpr bool IsBinarySearchTree() const { return IsBinarySearchTree(GetRootIndex()); }

    constexpr bool IsMinimalBinaryTree() const { return true; }

    constexpr bool IsBalancedBinaryTree() const { return true; }

    constexpr bool IsFullBinaryTree() const { return IsFullBinaryTree(GetRootIndex()); }

    constexpr bool IsCompleteBinaryTree() const { return IsCompleteBinaryTree(GetRootIndex()); }

    constexpr bool IsPerfectBinaryTree() const { return (IsFullBinaryTree() && IsCompleteBinaryTree()); }

  private:
    static constexpr index_type kRootIndex = 0UL;
    enum class SideView : std::uint8_t
    {
        kLeft,
        kRight,
        kTop,
        kBottom
    };

    constexpr index_type GetRootIndex() const { return kRootIndex; }

    constexpr index_type GetNodeIndex() const { return (GetSize() - 1UL); }

    constexpr index_type GetLeftNodeIndex(const index_type index) const { return (index * 2UL) + 1UL; }

    constexpr index_type GetRightNodeIndex(const index_type index) const { return (index * 2UL) + 2UL; }

    constexpr index_type GetParentNodeIndex(const index_type index) const { return ((index - 1UL) / 2UL); }

    constexpr bool IsEmpty() const { return (0UL == GetSize()); }

    constexpr bool IsFull() const { return (GetSize() >= GetCapacity()); }

    constexpr bool IsRootNode(const index_type index) const { return (index == GetRootIndex()); }

    constexpr bool IsNodeIndexValid(const index_type index) const { return (index < GetMaxNodes()); }

    constexpr bool IsNodeValid(const index_type index) const { return (GetNodeValue(index) != GetInvalidValue()); }

    constexpr bool IsLeafNode(const index_type index) const
    {
        return ((!HasLeftNode(index)) && (!HasRightNode(index)));
    }

    constexpr bool HasValidNode(const index_type index) const
    {
        return (IsNodeIndexValid(index) && IsNodeValid(index));
    }

    constexpr bool HasLeftNode(const index_type index) const
    {
        return (IsNodeIndexValid(GetLeftNodeIndex(index)) && IsNodeValid(GetLeftNodeIndex(index)));
    }

    constexpr bool HasRightNode(const index_type index) const
    {
        return (IsNodeIndexValid(GetRightNodeIndex(index)) && IsNodeValid(GetRightNodeIndex(index)));
    }

    constexpr value_type GetInvalidValue() const { return invalid_value_; }

    constexpr size_type GetMaxNodes() const
    {
        /// total nodes before level = 2 ^ (l + 1) - 1, where l = level
        return static_cast<size_type>(std::pow(2UL, GetMaxLevel(GetSize()) + 1UL) - 1UL);
    }

    constexpr size_type GetMaxLevel(const size_type size) const
    {
        /// total nodes before level = 2 ^ (l + 1) - 1.
        /// Hence for given total nodes, level = ceil(log2(total_nodes + 1)) - 1
        return (static_cast<size_type>(std::ceil(std::log2(size + 1UL))) - 1UL);
    }

    constexpr value_type GetNodeValue(const index_type index) const { return buffer_.at(index); }

    constexpr void SetNodeValue(const index_type index, const value_type& value) { buffer_.at(index) = value; }

    constexpr void SetLeftNodeValue(const index_type index, const value_type& value)
    {
        SetNodeValue(GetLeftNodeIndex(index), value);
    }

    constexpr void SetRightNodeValue(const index_type index, const value_type& value)
    {
        SetNodeValue(GetRightNodeIndex(index), value);
    }

    constexpr void InOrder(const index_type index, traversal_container& traversal) const
    {
        if (HasValidNode(index))
        {
            InOrder(GetLeftNodeIndex(index), traversal);
            traversal.push_back(GetNodeValue(index));
            InOrder(GetRightNodeIndex(index), traversal);
        }
    }

    constexpr void PostOrder(const index_type index, traversal_container& traversal) const
    {
        if (IsNodeIndexValid(index))
        {
            InOrder(GetLeftNodeIndex(index), traversal);
            InOrder(GetRightNodeIndex(index), traversal);
            traversal.push_back(GetNodeValue(index));
        }
    }

    constexpr void PreOrder(const index_type index, traversal_container& traversal) const
    {
        if (IsNodeIndexValid(index))
        {
            traversal.push_back(GetNodeValue(index));
            InOrder(GetLeftNodeIndex(index), traversal);
            InOrder(GetRightNodeIndex(index), traversal);
        }
    }

    constexpr void SideViewTraversal(const index_type index,
                                     const SideView side_view,
                                     traversal_container& traversal) const
    {
        if (IsNodeIndexValid(index))
        {
            std::queue<index_type> queue{};
            queue.push(index);

            while (!queue.empty())
            {
                const auto begin = 0UL;
                const auto end = queue.size();
                const auto last = end - 1UL;
                for (auto i = begin; i < end; ++i)
                {
                    const index_type current_index = queue.front();
                    queue.pop();

                    bool capture = false;
                    switch (side_view)
                    {
                        case SideView::kLeft:
                        {
                            capture = (i == begin);
                            break;
                        }
                        case SideView::kRight:
                        {
                            capture = (i == last);
                            break;
                        }
                        case SideView::kTop:
                        {
                            capture = ((i == begin) || (i == last));
                            break;
                        }
                        case SideView::kBottom:
                        {
                            capture = IsLeafNode(current_index);
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }

                    if (capture)
                    {
                        traversal.push_back(GetNodeValue(current_index));
                    }

                    if (HasLeftNode(current_index))
                    {
                        queue.push(GetLeftNodeIndex(current_index));
                    }
                    if (HasRightNode(current_index))
                    {
                        queue.push(GetRightNodeIndex(current_index));
                    }
                }
            }
        }
    }

    void LevelOrder(const index_type index, traversal_container& traversal) const
    {
        std::queue<index_type> queue{};
        queue.push(index);

        while (!queue.empty())
        {
            const index_type current_index = queue.front();
            queue.pop();

            traversal.push_back(GetNodeValue(current_index));

            if (HasLeftNode(current_index))
            {
                queue.push(GetLeftNodeIndex(current_index));
            }
            if (HasRightNode(current_index))
            {
                queue.push(GetRightNodeIndex(current_index));
            }
        }
    }

    constexpr size_type MaxDepth(const index_type index) const
    {
        size_type max_depth = 0UL;
        if (IsNodeIndexValid(index))
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
        if (IsNodeIndexValid(index))
        {
            if (HasLeftNode(index) && (MaxValue(GetLeftNodeIndex(index)) > GetNodeValue(index)))
            {
                is_binary_search_tree = false;
            }
            else if (HasRightNode(index) && (MinValue(GetRightNodeIndex(index)) <= GetNodeValue(index)))
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

    constexpr bool IsFullBinaryTree(const index_type index) const
    {
        bool is_full_binary_tree = true;
        if (IsNodeIndexValid(index))
        {
            if (IsLeafNode(index))
            {
                is_full_binary_tree = true;
            }
            else if (HasLeftNode(index) && HasRightNode(index))
            {
                is_full_binary_tree =
                    IsFullBinaryTree(GetLeftNodeIndex(index)) && IsFullBinaryTree(GetRightNodeIndex(index));
            }
            else
            {
                is_full_binary_tree = false;
            }
        }
        return is_full_binary_tree;
    }

    constexpr bool IsCompleteBinaryTree(const index_type index) const
    {
        bool is_complete_binary_tree = true;
        if (IsNodeIndexValid(index))
        {
            if (IsLeafNode(index))
            {
                is_complete_binary_tree = true;
            }
            else if (HasLeftNode(index) && HasRightNode(index))
            {
                is_complete_binary_tree =
                    IsCompleteBinaryTree(GetLeftNodeIndex(index)) && IsCompleteBinaryTree(GetRightNodeIndex(index));
            }
            else if (HasLeftNode(index) && !HasRightNode(index))
            {
                is_complete_binary_tree = IsCompleteBinaryTree(GetLeftNodeIndex(index));
            }
            else
            {
                is_complete_binary_tree = false;
            }
        }
        return is_complete_binary_tree;
    }

    const value_type invalid_value_;
    size_type size_;
    container buffer_;
};

}  // namespace tree

#endif  /// ALGORITHMS_TREE_BINARY_TREE_H
