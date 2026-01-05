#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/floor-in-bst/1

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
    void solve(Node *root, int &x, int &answer)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->data == x)
        {
            answer = x;
            return;
        }
        else if (root->data > x)
        {
            solve(root->left, x, answer);
        }
        else
        {
            answer = root->data;
            solve(root->right, x, answer);
        }
    }

    int floor(Node *root, int x)
    {
        int answer = -1;
        solve(root, x, answer);

        return answer;
    }
};
