#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

class myStack
{
public:
    vector<int> arr;
    int top;
    int capacity;

    myStack(int n)
    {
        arr.resize(n);
        top = -1;
        capacity = n;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void push(int x)
    {
        arr[++top] = x;
    }

    void pop()
    {
        if (isEmpty())
            return;
        --top;
    }

    int peek()
    {
        if (isEmpty())
            return -1;

        return arr[top];
    }
};