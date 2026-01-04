#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

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
    vector<int> bottomView(Node *root)
    {
        vector<int> answer;

        if (root == NULL)
        {
            return answer;
        }

        map<int, Node *> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            mp[it.second] = it.first;

            if (it.first->left)
                q.push({it.first->left, it.second - 1});
            if (it.first->right)
                q.push({it.first->right, it.second + 1});
        }

        for (auto it : mp)
        {
            answer.push_back(it.second->data);
        }

        return answer;
    }
};