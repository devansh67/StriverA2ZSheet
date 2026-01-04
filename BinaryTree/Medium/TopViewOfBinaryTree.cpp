#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

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
    vector<int> topView(Node *root)
    {
        vector<int> answer;

        if (root == NULL)
        {
            return answer;
        }
        queue<pair<Node *, int>> q;
        map<int, int> mp;
        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            if (mp.find(it.second) == mp.end())
            {
                mp[it.second] = it.first->data;
            }

            if (it.first->left)
                q.push({it.first->left, it.second - 1});
            if (it.first->right)
                q.push({it.first->right, it.second + 1});
        }

        for (auto it : mp)
        {
            answer.push_back(it.second);
        }

        return answer;
    }
};

class SolutionDfs
{
    map<int, pair<int, int>> mp;

public:
    void solve(Node *root, int row, int col)
    {
        if (root == NULL)
        {
            return;
        }

        if (mp.find(col) == mp.end() || row < mp[col].first)
        {
            mp[col] = {row, root->data};
        }

        solve(root->left, row + 1, col - 1);
        solve(root->right, row + 1, col + 1);
    }

    vector<int> topView(Node *root)
    {
        vector<int> answer;

        if (root == NULL)
        {
            return answer;
        }

        solve(root, 0, 0);

        for (auto it : mp)
        {
            answer.push_back(it.second.second);
        }

        return answer;
    }
};