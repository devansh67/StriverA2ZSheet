#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/merge-k-sorted-lists/description/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct comparator
{
    bool operator()(ListNode *a, ListNode *b) const
    {
        return a->val > b->val; // min-heap
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        priority_queue<ListNode *, vector<ListNode *>, comparator> pq;

        for (auto it : lists)
        {
            if (it != NULL)
            {
                pq.push(it);
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;

        while (!pq.empty())
        {
            auto minimum = pq.top();
            pq.pop();

            curr->next = minimum;
            curr = curr->next;

            if (minimum->next != NULL)
            {
                pq.push(minimum->next);
            }
        }

        return dummy->next;
    }
};