#include <iostream>
#include <vector>
#include <unordered_map>
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
    void traverseLeft(Node *root, vector<int> &answer)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        answer.push_back(root->data);
        if (root->left)
        {
            traverseLeft(root->left, answer);
        }
        else
        {
            traverseLeft(root->right, answer);
        }
    }

    void traverseLeaf(Node *root, vector<int> &answer)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL && root->right == NULL)
        {
            answer.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, answer);
        traverseLeaf(root->right, answer);
    }

    void traverseRight(Node *root, vector<int> &answer)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        if (root->right)
        {
            traverseRight(root->right, answer);
        }
        else if (root->left)
        {
            traverseRight(root->left, answer);
        }

        answer.push_back(root->data);
    }

    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> answer;

        if (root == NULL)
        {
            return answer;
        }

        answer.push_back(root->data);

        traverseLeft(root->left, answer);
        traverseLeaf(root->left, answer);
        traverseLeaf(root->right, answer);
        traverseRight(root->right, answer);

        return answer;
    }
};
