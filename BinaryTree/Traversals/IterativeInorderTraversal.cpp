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
    vector<int> inOrder(Node *root)
    {
        stack<Node *> st;
        Node *curr = root;

        vector<int> answer;

        while (curr != nullptr || !st.empty())
        {
            while (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            answer.push_back(curr->data);
            st.pop();

            curr = curr->right;
        }

        return answer;
    }
};