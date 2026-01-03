#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://www.geeksforgeeks.org/problems/huffman-encoding3345/1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class comparator
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    void traverse(Node *root, vector<string> &answer, string temp)
    {
        if (root->left == NULL && root->right == NULL)
        {
            answer.push_back(temp);
            return;
        }

        traverse(root->left, answer, temp + '0');
        traverse(root->right, answer, temp + '1');
    }

    vector<string> huffmanCodes(string str, vector<int> freq, int n)
    {
        priority_queue<Node *, vector<Node *>, comparator> pq;

        for (auto it : freq)
        {
            Node *temp = new Node(it);
            pq.push(temp);
        }

        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();

            Node *right = pq.top();
            pq.pop();

            Node *curr = new Node(left->data + right->data);
            curr->left = left;
            curr->right = right;

            pq.push(curr);
        }

        Node *root = pq.top();
        vector<string> answer;
        string temp = "";

        traverse(root, answer, temp);

        return answer;
    }
};