#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/binary-tree-representation/1

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);
}

class Solution
{
public:
    void create_tree(node *root, vector<int> &arr)
    {
        int n = arr.size();
        int i = 0;
        queue<node *> q;
        q.push(root);
        i++;

        while (!q.empty() && i < n)
        {
            auto it = q.front();
            q.pop();

            node *temp1 = newNode(arr[i]);
            it->left = temp1;
            q.push(temp1);
            i++;

            if (i != n)
            {
                node *temp2 = newNode(arr[i]);
                it->right = temp2;
                q.push(temp2);
                i++;
            }
        }
    }
};