#include "problem_statement/minimize_path_value.hpp"

#include <algorithm>
#include <limits>
#include <vector>

namespace problem_statement
{
int getMinimumStress(const int N,
                     const std::vector<int>& from,
                     const std::vector<int>& to,
                     const std::vector<int>& weight,
                     int source,
                     int destination)
{
    int min_total_stress{std::numeric_limits<int>::max()};
    int min_stress{std::numeric_limits<int>::max()};

    if (source == destination)
    {
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        if (from[i] == source)
        {
            const int total_stress = weight[i] + getMinimumStress(N, from, to, weight, to[i], destination);
            if (total_stress != -1 && (total_stress < min_total_stress))
            {
                min_total_stress = total_stress;
                min_stress = std::min({weight[i], min_stress});
            }
        }
    }
    if (min_total_stress == std::numeric_limits<int>::max())
    {
        return -1;
    }
    return min_stress;
}
}  // namespace problem_statement
