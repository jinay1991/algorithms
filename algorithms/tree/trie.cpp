///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "algorithms/tree/trie.h"

namespace tree
{
Trie::Trie() : root_{CreateNode()} {}

Trie::~Trie()
{
    /// TODO: delete all nodes
}

void Trie::InsertDictionary(const std::vector<std::string>& dictionary)
{
    for (auto& word : dictionary)
    {
        Insert(word);
    }
}

void Trie::Insert(const std::string& word)
{
    struct Node* current = root_;

    for (auto i = 0UL; i < word.length(); ++i)
    {
        const std::size_t index = word[i] - 'a';
        if (!current->children[index])
        {
            current->children[index] = CreateNode();
        }

        current = current->children[index];
    }

    current->is_end_of_word = true;
}

bool Trie::HasWord(const std::string& word) const
{
    struct Node* current = root_;
    for (auto i = 0UL; i < word.length(); ++i)
    {
        const auto index = word[i] - 'a';

        if (!current->children[index])
            return false;

        current = current->children[index];
    }

    return (current != NULL && current->is_end_of_word);
}

std::vector<std::vector<std::string>> Trie::GetSuggestionList(const std::vector<std::string>& queries,
                                                              const std::size_t number_of_suggestions)
{
    std::vector<std::vector<std::string>> suggestion_list;
    for (auto& query : queries)
    {
        const auto suggestions = GetSuggestions(query, number_of_suggestions);
        suggestion_list.push_back(suggestions);
    }
    return suggestion_list;
}

std::vector<std::string> Trie::GetSuggestions(const std::string& query, const std::size_t number_of_suggestions)
{
    std::vector<std::string> result;
    struct Node* current = root_;

    for (auto i = 0UL; i < query.length(); i++)
    {
        const auto index = query[i] - 'a';

        if (!current->children[index])
        {
            return {};
        }

        current = current->children[index];
    }

    bool is_word = (current->is_end_of_word == true);
    bool is_last = IsLastNode(current);

    if (is_word && is_last)
    {
        return {};
    }

    if (!is_last)
    {
        std::string prefix = query;
        CheckSuggestions(current, prefix, result);
    }
    return result;
}

void Trie::CheckSuggestions(struct Node* node, std::string& prefix, std::vector<std::string>& container)
{
    if (node->is_end_of_word)
    {
        // Found the match
        container.push_back(prefix);
    }

    if (IsLastNode(node))
    {
        return;
    }

    for (auto i = 0UL; i < kAlphabetSize; i++)
    {
        if (node->children[i])
        {
            prefix.push_back(i + 'a');
            CheckSuggestions(node->children[i], prefix, container);
            prefix.pop_back();
        }
    }
}

bool Trie::IsLastNode(const struct Node* node) noexcept
{
    for (auto i = 0UL; i < kAlphabetSize; i++)
    {
        if (node->children[i])
        {
            return false;
        }
    }
    return true;
}

}  // namespace tree
