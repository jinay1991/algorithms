///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/find_team_players.h"

namespace problem_statement
{
#if 0
class Graph
{
  public:
    Graph() : node_{} {}

    /// O(m) + O(m + n) + O(n)
    /// rashford -> pogba -> cavani
    /// saka -> pepe
    void Insert(const std::pair<std::string, std::string>& value)
    {
        bool new_entry = true;
        for (auto& current_node : node_)
        {
            const auto it = std::find_if(current_node.cbegin(),
                                         current_node.cend(),
                                         [&value](const auto& n) { return n == value.first || n == value.second; });
            if (it != current_node.cend())
            {
                new_entry = false;
                current_node.push_back(value.first);
                current_node.push_back(value.second);
            }
        }
        if (new_entry)
        {
            std::set<std::string> current_value{value.first, value.second};
            node_.push_back(current_value);
        }
    }

    bool Query(const std::string& name_1, const std::string& name_2) const
    {
        bool result = false;
        for (auto& current_node : node_)
        {
            result = current_node.cend() != std::find(current_node.cbegin(), current_node.cend(), name_1);
            result &= current_node.cend() != std::find(current_node.cbegin(), current_node.cend(), name_2);
            if (result)
            {
                break;
            }
        }

        return result;
    }

  private:
    std::list<std::set<Node>> node_;
};

// To execute C++, please define "int main()"
int main()
{
    std::vector<std::pair<std::string, std::string>> inputs
    {
        {"rashford", "pogba"}, {"pogba", "cavani"}, {"pepe", "saka"};

        Graph graph{};
        for (auto& p : inputs)
        {
            graph.Insert(p);
        }

        const auto result = graph.Query("rashford", "cavani");
        std::cout << "Result: " << std::boolalpha << result << std::endl;
        return 0;
    }

    /*
    Your previous Python 3 content is preserved below:

    """
    You are given:
    1. A list of M pairs of people full names: e.g., [("rashford", "pogba"), ("pogba", "cavani")]) where a pair (x, y)
    means that x and y are the teammates.
    2. A query which consists of two names: A and B.

    The task is to figure out whether players A and B play for the same team.

    Example 1:
    Input: pairs = [("rashford", "pogba"), ("pogba", "cavani")], A = "rashford", B = "cavani"
    Output: yes

    /// v1: rashford, pogba, cavani
    /// v2:

    Example 2:
    Input: pairs = [("rashford", "pogba"), ("pogba", "rashford"), ("fernandez", "telles"), ("telles", "greenwood"),
    ("pepe", "saka"), ("saka", "rashford")], A = "rashford", B = "greenwood" Output: false

    /// v1: rashford, pogba,
    /// v2: "fernandez", "telles", greenwood,
    /// v3: pepe saka,


    ///
    /// pogba
    ///    |
    /// rashford --> Saka
    ///

                ("rashford", "pogba"),
                ("rashford", "cavani"),
                ("cavani", "pogba"),
                ("cavani", "beek"),
                ("beek", "fernandez"),
                ("fernandez", "telles"),
                ("telles", "greenwood"),
                # Arsenal
                ("aubameyang", "ozil"),
                ("ozil", "partey"),
                ("partey", "ozil"),
                ("partey", "gabriel"),
                ("gabriel", "willian"),
                ("willian", "pepe"),
                ("pepe", "saka"),
    */
#endif  // #if 0
}  // namespace problem_statement
