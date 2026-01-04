#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

// https://www.geeksforgeeks.org/problems/preorder-traversal/1

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// 2 Stack solution
class Solution
{
public:
    vector<int> postOrder(Node *root)
    {
        stack<Node *> st1, st2;
        vector<int> answer;

        st1.push(root);

        while (!st1.empty())
        {
            auto it = st1.top();
            st1.pop();

            st2.push(it);
            if (it->left)
                st1.push(it->left);
            if (it->right)
                st1.push(it->right);
        }

        while (!st2.empty())
        {
            auto it = st2.top();
            st2.pop();
            answer.push_back(it->data);
        }

        return answer;
    }
};