#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string answer = "";
        if (root == NULL)
        {
            return answer;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            if (it == nullptr)
            {
                answer += '#,';
            }
            else
            {
                answer += to_string(it->val) + ',';
                q.push(it->left);
                q.push(it->right);
            }
        }

        return answer;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
        {
            return nullptr;
        }

        stringstream ss(data);
        string token;

        getline(ss, token, ',');
        if (token == "#")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(token));

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            if (!getline(ss, token, ','))
                break;

            if (token != "#")
            {
                it->left = new TreeNode(stoi(token));
                q.push(it->left);
            }

            if (!getline(ss, token, ','))
                break;

            if (token != "#")
            {
                it->right = new TreeNode(stoi(token));
                q.push(it->right);
            }
        }

        return root;
    }
};
