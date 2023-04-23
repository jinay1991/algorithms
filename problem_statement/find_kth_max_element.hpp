///
/// @file
/// @copyright Copyright (C) 2023. MIT License.
///
#ifndef ALGORITHM_PROBLEM_STATEMENT_FIND_KTH_MAX_ELEMENT_HPP
#define ALGORITHM_PROBLEM_STATEMENT_FIND_KTH_MAX_ELEMENT_HPP

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <limits>
#include <type_traits>

namespace problem_statement
{
/// @brief Find Kth Max Element from the Array
///
/// time-complexity: O(N + K)
///
/// @tparam T array element type
/// @tparam kMaxElements array element size
///
/// @param[in] input_array Input Array
/// @param[in] K value of K
///
/// @return Kth max element
template <typename T, const std::size_t kMaxElements, std::enable_if_t<std::is_arithmetic<T>::value, bool> = true>
constexpr T find_kth_max_element(const std::array<T, kMaxElements>& input_array, const std::size_t K)
{
    if (K > input_array.size())
    {
        std::cerr << "K (" << K << ") cannot be greater than the provided array size (" << input_array.size() << ")."
                  << std::endl;
        return std::numeric_limits<T>::infinity();
    }

    if (K <= static_cast<T>(0))
    {
        std::cerr << "K (" << K << ") cannot be zero." << std::endl;
        return std::numeric_limits<T>::infinity();
    }

    T kth_element{};
    std::array<T, kMaxElements> sorted_input_array{input_array};

    for (std::size_t current_index{0UL}; current_index < sorted_input_array.size(); ++current_index)
    {
        for (std::size_t next_index{0UL}; next_index < sorted_input_array.size() - 1UL; ++next_index)
        {
            T& current_element{sorted_input_array.at(current_index)};
            T& next_element{sorted_input_array.at(next_index)};

            if (current_element > next_element)
            {
                const T temp_current_element{current_element};
                current_element = next_element;
                next_element = temp_current_element;
            }
        }
    }

    kth_element = sorted_input_array.at(K - 1UL);

    std::cout << "sorted array: ";
    std::for_each(
        sorted_input_array.cbegin(), sorted_input_array.cend(), [](const auto& value) { std::cout << value << " "; });

    return kth_element;
}
}  // namespace problem_statement

#endif  /// ALGORITHM_PROBLEM_STATEMENT_FIND_KTH_MAX_ELEMENT_HPP
