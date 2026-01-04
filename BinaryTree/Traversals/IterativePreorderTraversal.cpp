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

class Solution
{
public:
    vector<int> preOrder(Node *root)
    {
        stack<Node *> st;
        st.push(root);

        vector<int> answer;

        while (!st.empty())
        {
            auto it = st.top();
            answer.push_back(it->data);
            st.pop();

            if (it->right)
                st.push(it->right);
            if (it->left)
                st.push(it->left);
        }

        return answer;
    }
};