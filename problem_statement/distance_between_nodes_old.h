/*
I want you to find the distance between two nodes in a ordered binary tree.
Distance in this case being how many nodes are between the two nodes if you traverse the tree.

So for example if you have a tree build from something like:
tree.insert(1)
tree.insert(3)
tree.insert(2)
tree.insert(8)
tree.insert(5)
tree.insert(13)
           1
         3
     8     2
13      5
numberOfNodesBetween(1, 2) == 1 because there is one node (3) between 1 and 2
numberOfNodesBetween(5, 2) == 2 because there are two nodes (8 and 3) between 5 and 2
*/

using namespace std;

class Tree
{
    // ...
};

template <typename T>
size_t distance(const Tree<T>& root, const T& node_1, const T& node_2)
{
    std::queue<T> queue;
    std::vector<std::pair<T, bool>> visited;

    const T start_node = std::min(node_1, node_2);  // min
    const T end_node = std::max(node_1, node_2);    // max

    int count = 0;
    bool is_start_found = false;
    queue.push(root);

    while (!queue.empty())
    {

        //
        if (!is_start_found)
        {
            const auto size = queue.size();
            for (auto i = 0; i < size; ++i)
            {
                const auto node = queue.top();
                queue.pop();

                if (node == start_node)
                {
                    count++;
                    is_start_found = true;
                    break;
                }

                if (node->right)
                {
                    queue.push(node->right);
                }
                if (node->left)
                {
                    queue.push(node->left);
                }
            }
        }
        else
        {
            const auto node = queue.top();
            queue.pop();

            if (node == end_node)
            {
                count++;
                break;
            }
            count++;
            if (node->right)
            {
                queue.push(node->right);
            }
            if (node->left)
            {
                queue.push(node->left);
            }
        }

        // if (node->right) {
        //     is_start_node_found = (node->right == start_node);
        //     queue.push(node->right);
        // }

        // if (node->left) {
        //     is_start_node_found = (node->left == start_node);
        //     queue.push(node->left);
        // }

        // if (is_start_node_found)
        // {
        //     count++;
        // }
    }
    return count;
}
