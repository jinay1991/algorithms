#include <vector>

namespace library
{
int getMinimumStress(const int N,
                     const std::vector<int>& from,
                     const std::vector<int>& to,
                     const std::vector<int>& weight,
                     int source,
                     int destination);

}  // namespace library
