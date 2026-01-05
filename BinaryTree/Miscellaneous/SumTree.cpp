#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/sum-tree/1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int solve(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        if (root->left == NULL && root->right == NULL)
        {
            return root->data;
        }

        int left_data = solve(root->left);
        ;
        int right_data = solve(root->right);

        if (left_data == -1 || right_data == -1)
        {
            return -1;
        }

        if (root->data != left_data + right_data)
        {
            return -1;
        }

        return root->data + left_data + right_data;
    }

    bool isSumTree(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        return solve(root) != -1;
    }
};