#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int temp = q.front();
        q.pop();

        return temp;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.size() == 0;
    }
};