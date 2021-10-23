///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/tree/max_heap.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <ostream>
#include <sstream>

namespace tree
{
namespace
{
constexpr std::size_t kMaxNumberOfNodes{10UL};

class MaxHeapFixture : public ::testing::Test
{
  public:
    MaxHeapFixture() : unit_{} {}

  protected:
    MaxHeap<std::int32_t, kMaxNumberOfNodes> unit_;
};

TEST_F(MaxHeapFixture, Push_GivenTypicalNode_ExpectSameNodePushed)
{
    // Given
    const std::int32_t node = 3;
    ASSERT_EQ(unit_.GetSize(), 0UL);

    // When
    unit_.Push(node);

    // Then
    EXPECT_EQ(unit_.GetSize(), 1UL);
    EXPECT_EQ(unit_.GetNodeValue(0UL), node);
}

TEST_F(MaxHeapFixture, Push_GivenTypicalNodes_ExpectSameNodesPushed)
{
    // Given
    ASSERT_EQ(unit_.GetSize(), 0UL);

    // When
    unit_.Push(3);  // root
    unit_.Push(2);  // left
    unit_.Push(1);  // left

    // Then
    EXPECT_EQ(unit_.GetSize(), 3UL);
    EXPECT_EQ(unit_.GetNodeValue(0UL), 3);
    EXPECT_EQ(unit_.GetNodeValue(1UL), 2);
    EXPECT_EQ(unit_.GetNodeValue(2UL), 1);
}

TEST_F(MaxHeapFixture, Pop_GivenTypicalMaxHeap_ExpectRootNodePopped)
{
    // Given
    unit_.Push(10);
    unit_.Push(15);
    unit_.Push(20);
    unit_.Push(17);
    unit_.Push(25);
    ASSERT_EQ(unit_.GetSize(), 5UL);
    ASSERT_EQ(unit_.GetNodeValue(0UL), 25);
    ASSERT_EQ(unit_.GetNodeValue(1UL), 20);
    ASSERT_EQ(unit_.GetNodeValue(2UL), 15);
    ASSERT_EQ(unit_.GetNodeValue(3UL), 10);
    ASSERT_EQ(unit_.GetNodeValue(4UL), 17);

    // When
    const auto value = unit_.Pop();

    // Then
    EXPECT_EQ(value, 25);
    EXPECT_EQ(unit_.GetSize(), 4UL);
    EXPECT_EQ(unit_.GetNodeValue(0UL), 20);
    EXPECT_EQ(unit_.GetNodeValue(1UL), 17);
    EXPECT_EQ(unit_.GetNodeValue(2UL), 15);
    EXPECT_EQ(unit_.GetNodeValue(3UL), 10);  // last element in heap
    EXPECT_EQ(unit_.GetNodeValue(4UL), 25);  // popped element at end (in free space)
}

TEST_F(MaxHeapFixture, GetCapacity_GivenTypicalMaxHeap_ExpectMaxCapacity)
{
    // When
    const auto capacity = unit_.GetCapacity();

    // Then
    EXPECT_EQ(capacity, kMaxNumberOfNodes);
}

TEST_F(MaxHeapFixture, Reset_GivenTypicalMaxHeap_ExpectResetValues)
{
    // Given
    unit_.Push(3);
    unit_.Push(2);
    unit_.Push(4);
    ASSERT_EQ(unit_.GetSize(), 3UL);

    // When
    unit_.Reset();

    // Then
    EXPECT_EQ(unit_.GetSize(), 0UL);
}

TEST_F(MaxHeapFixture, IsEmpty_GivenTypicalMaxHeap_ExpectTrue)
{
    // Given
    ASSERT_EQ(unit_.GetSize(), 0UL);

    // When/Then
    EXPECT_TRUE(unit_.IsEmpty());
}

TEST_F(MaxHeapFixture, IsEmpty_GivenTypicalMaxHeap_ExpectFalse)
{
    // Given
    unit_.Push(10);
    ASSERT_EQ(unit_.GetSize(), 1UL);

    // When/Then
    EXPECT_FALSE(unit_.IsEmpty());
}

TEST_F(MaxHeapFixture, IsFull_GivenTypicalMaxHeap_ExpectTrue)
{
    // Given
    unit_.Push(10);
    unit_.Push(9);
    unit_.Push(8);
    unit_.Push(7);
    unit_.Push(6);
    unit_.Push(5);
    unit_.Push(4);
    unit_.Push(3);
    unit_.Push(2);
    unit_.Push(1);
    ASSERT_EQ(unit_.GetSize(), kMaxNumberOfNodes);

    // When/Then
    EXPECT_TRUE(unit_.IsFull());
}

TEST_F(MaxHeapFixture, IsFull_GivenTypicalMaxHeap_ExpectFalse)
{
    // Given
    unit_.Push(10);
    unit_.Push(9);
    unit_.Push(8);
    unit_.Push(7);
    unit_.Push(6);
    unit_.Push(5);
    unit_.Push(4);
    unit_.Push(3);
    unit_.Push(2);
    ASSERT_EQ(unit_.GetSize(), 9UL);

    // When/Then
    EXPECT_FALSE(unit_.IsFull());
}

TEST_F(MaxHeapFixture, StreamOperator_GivenTypicalMaxHeap_ExpectStreamRepresentationOfTree)
{
    // Given
    std::stringstream stream;
    unit_.Push(3);
    unit_.Push(2);
    unit_.Push(1);
    unit_.Push(15);
    unit_.Push(5);
    unit_.Push(4);
    unit_.Push(45);
    ASSERT_EQ(unit_.GetSize(), 7UL);

    // When/Then
    stream << unit_;

    // Then
    EXPECT_EQ(stream.str(), " 45 5 15 2 3 1 4");
}

TEST_F(MaxHeapFixture, GetMaxNodeValue_GivenTypicalMaxHeap_ExpectMaxNodeValue)
{
    // Given
    unit_.Push(3);
    unit_.Push(2);
    unit_.Push(1);
    unit_.Push(15);
    unit_.Push(5);
    unit_.Push(4);
    unit_.Push(45);
    ASSERT_EQ(unit_.GetSize(), 7UL);

    // When/Then
    const auto max_value = unit_.GetMaxNodeValue();

    // Then
    EXPECT_EQ(max_value, 45);
}

TEST_F(MaxHeapFixture, GetDepth_GivenTypicalMaxHeap_ExpectMaxHeapDepth)
{
    // Given
    unit_.Push(3);
    unit_.Push(2);
    unit_.Push(1);
    unit_.Push(15);
    unit_.Push(5);
    unit_.Push(45);
    ASSERT_EQ(unit_.GetSize(), 6UL);

    // When/Then
    const auto depth = unit_.GetDepth();

    // Then
    EXPECT_EQ(depth, 3UL);
}

TEST_F(MaxHeapFixture, GetLeftView_GivenTypicalMaxHeap_ExpectLeftViewOfMaxHeap)
{
    // Given
    unit_.Push(3);
    unit_.Push(2);
    unit_.Push(1);
    unit_.Push(15);
    unit_.Push(5);
    unit_.Push(4);
    unit_.Push(45);
    ASSERT_EQ(unit_.GetSize(), 7UL);

    // When/Then
    const auto left_view = unit_.GetLeftView();

    // Then
    ASSERT_EQ(left_view.size(), 4UL);
    EXPECT_EQ(left_view.at(0UL), 45);
    EXPECT_EQ(left_view.at(1UL), 5);
    EXPECT_EQ(left_view.at(2UL), 2);
    EXPECT_EQ(left_view.at(3UL), 0);  // empty nodes
}

}  // namespace
}  // namespace tree
