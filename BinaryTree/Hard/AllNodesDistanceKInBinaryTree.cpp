#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    unordered_map<TreeNode *, TreeNode *> parentMp;

public:
    void preorderTraversal(TreeNode *root, TreeNode *parent)
    {
        if (root == NULL)
        {
            return;
        }

        parentMp[root] = parent;
        preorderTraversal(root->left, root);
        preorderTraversal(root->right, root);
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> answer;
        if (root == NULL)
        {
            return answer;
        }

        preorderTraversal(root, NULL);

        queue<TreeNode *> q;
        q.push(target);
        unordered_set<TreeNode *> visited;

        while (!q.empty() and k)
        {
            k--;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto it = q.front();
                q.pop();

                visited.insert(it);

                if (it->left && !visited.count(it->left))
                    q.push(it->left);
                if (it->right && !visited.count(it->right))
                    q.push(it->right);
                if (parentMp[it] && !visited.count(parentMp[it]))
                    q.push(parentMp[it]);
            }
        }

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            answer.push_back(it->val);
        }

        return answer;
    }
};