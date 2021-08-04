///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include <algorithm>
#include <vector>

namespace problem_statement
{

template <typename T>
void InsertSorted1(std::vector<T>& buffer, const T& data)
{
    const auto it = std::lower_bound(buffer.begin(), buffer.end(), data);
    buffer.insert(it, data);
}

template <typename T>
void InsertSorted2(std::vector<T>& buffer, const T& data)
{
    auto it = buffer.begin();
    while (it != buffer.end())
    {
        if (*it > data)
        {
            break;
        }
        ++it;
    }

    buffer.insert(it, data);
}

template <typename T>
void InsertSorted3(std::vector<T>& buffer, const T& data)
{
    auto it = buffer.rbegin();
    while (it != buffer.rend())
    {
        if (*it < data)
        {
            break;
        }
        ++it;
    }
    buffer.insert(it.base(), data);
}
}  // namespace problem_statement
