#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/children-sum-parent/1

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
    bool solve(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }

        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        int left_data = 0;
        int right_data = 0;

        if (root->left)
            left_data = root->left->data;
        if (root->right)
            right_data = root->right->data;

        if (root->data != left_data + right_data)
        {
            return false;
        }

        bool flag1 = solve(root->left);
        bool flag2 = solve(root->right);

        return flag1 && flag2;
    }

    bool isSumProperty(Node *root)
    {
        return solve(root);
    }
};