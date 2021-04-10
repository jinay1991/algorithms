///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "argoai/calculator.h"

#include <functional>
#include <limits>
#include <sstream>
#include <string>
#include <unordered_map>

namespace argoai
{
constexpr double kEpsilon = std::numeric_limits<double>::epsilon();
constexpr double kInfinity = std::numeric_limits<double>::infinity();

const std::unordered_map<char, std::function<double(double, double)>> operations{
    {'+', [](const double a, const double b) -> double { return (a + b); }},
    {'-', [](const double a, const double b) -> double { return (a - b); }},
    {'*', [](const double a, const double b) -> double { return (a * b); }},
    {'/', [](const double a, const double b) -> double { return (b != kEpsilon) ? (a / b) : kInfinity; }}};

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

}  // namespace argoai
