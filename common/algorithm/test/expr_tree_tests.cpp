///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "common/algorithm/expr_tree.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

namespace algorithm
{
namespace
{

class TreeFixture : public ::testing::Test
{
};

template <typename T>
class ExprTreeFixtureT : public TreeFixture, public ::testing::WithParamInterface<T>
{
};

using ExprTreeFixture_WithMultipleValues = ExprTreeFixtureT<std::string>;

INSTANTIATE_TEST_SUITE_P(ExprTree, ExprTreeFixture_WithMultipleValues, ::testing::Values("1+2", "10+20"));

TEST_P(ExprTreeFixture_WithMultipleValues, Insert_GivenMultipleValues_ExpectInsertedValues)
{
    // Given
    ExprTree tree;
    const std::string postfix_expression = GetParam();

    // When
    tree.Insert(postfix_expression);

    // Then
    EXPECT_EQ(tree.GetSize(), postfix_expression.size());
}

}  // namespace
}  // namespace algorithm
