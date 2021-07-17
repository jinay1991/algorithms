///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/calculator.h"

#include <functional>
#include <limits>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace problem_statement
{
constexpr double kEpsilon = std::numeric_limits<double>::epsilon();
constexpr double kInfinity = std::numeric_limits<double>::infinity();

const std::unordered_map<char, std::function<double(double, double)>> operations{
    {'+', [](const double a, const double b) -> double { return (a + b); }},
    {'-', [](const double a, const double b) -> double { return (a - b); }},
    {'*', [](const double a, const double b) -> double { return (a * b); }},
    {'/', [](const double a, const double b) -> double { return (b != kEpsilon) ? (a / b) : kInfinity; }}};

namespace
{
}  // namespace

double calculate(const std::string& input)
{
    double result = 0.0;
    std::istringstream stream{input};
    char ch = 0;
    while (stream.get(ch))
    {
        double value_1 = 0.0;
        double value_2 = 0.0;
        char op = 0;
        if (ch >= '0' && ch <= '9')
        {
            stream >> value_1 >> op >> value_2;
        }
        else
        {
            continue;
        }

        if (operations.find(op) != operations.end())
        {
            result = operations.at(op)(value_1, value_2);
        }
    }
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

template <typename T>
class Tree
{
  public:
    Tree() : root_{nullptr} {}

    explicit Tree(const Node<T>* root) : root_{root} {}

    void Insert(const T& value) {}

  private:
    std::string expression_;
    Node<T>* root_;
};

}  // namespace problem_statement
