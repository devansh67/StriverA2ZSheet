#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

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
    void findPredecessor(Node *root, int &key, Node *&pre)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->data == key || root->data > key)
        {
            findPredecessor(root->left, key, pre);
        }
        else
        {
            pre = root;
            findPredecessor(root->right, key, pre);
        }
    }

    void findSuccessor(Node *root, int &key, Node *&suc)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->data == key || root->data < key)
        {
            findSuccessor(root->right, key, suc);
        }
        else
        {
            suc = root;
            findSuccessor(root->left, key, suc);
        }
    }

    vector<Node *> findPreSuc(Node *root, int key)
    {
        vector<Node *> answer;

        Node *pre = NULL;
        findPredecessor(root, key, pre);

        Node *suc = NULL;
        findSuccessor(root, key, suc);

        answer.push_back(pre);
        answer.push_back(suc);

        return answer;
    }
};