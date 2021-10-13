///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef PROBLEM_STATEMENT_FIND_TEAM_PLATERS_H
#define PROBLEM_STATEMENT_FIND_TEAM_PLATERS_H

#include <map>

namespace problem_statement
{

template <typename T, std::size_t kMaxVertices>
class Graph
{
  public:
    Graph() : adjacency_list_{} {}

    explicit Graph(const std::initializer_list<std::pair<T, T>>& list)
    {
        for (auto& l : list)
        {
            AddEdge(l.first, l.second);
        }
    }

    void AddEdge(const std::size_t& from, const std::size_t& to) { adjacency_list_[from] = to; }
    bool Query(const T& /* from */, const T& /* to */) { return false; }

  private:
    std::map<T, std::list<T>> adjacency_list_;
};
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
}  // namespace problem_statement
#endif  /// PROBLEM_STATEMENT_FIND_TEAM_PLATERS_H
