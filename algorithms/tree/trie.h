///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#ifndef ALGORITHM_TREE_TRIE_H
#define ALGORITHM_TREE_TRIE_H

#include <cstdint>
#include <string>
#include <vector>

namespace tree
{

static constexpr std::size_t kAlphabetSize = 26UL;

struct Node
{
    struct Node* children[kAlphabetSize];
    bool is_end_of_word;
};

struct Node* CreateNode()
{
    struct Node* node = new Node;
    node->is_end_of_word = false;

    for (auto i = 0UL; i < kAlphabetSize; i++)
    {
        node->children[i] = nullptr;
    }

    return node;
}

class Trie
{
  public:
    Trie();
    ~Trie();

    void InsertDictionary(const std::vector<std::string>& dictionary);
    ;

    void Insert(const std::string& word);

    /// @return True if word is present in Trie, otherwise False
    bool HasWord(const std::string& word) const;

    std::vector<std::vector<std::string>> GetSuggestionList(const std::vector<std::string>& queries,
                                                            const std::size_t number_of_suggestions);
    std::vector<std::string> GetSuggestions(const std::string& query, const std::size_t number_of_suggestions);

  private:
    void CheckSuggestions(struct Node* node, std::string& prefix, std::vector<std::string>& container);
    bool IsLastNode(const struct Node* node) noexcept;

    struct Node* root_;
};
}  // namespace tree

#endif  /// ALGORITHM_TREE_TRIE_H
