#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class myStack
{

public:
    Node *top;
    myStack()
    {
        this->top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (isEmpty())
            return;
        Node *temp = top;
        top = top->next;
        delete (temp);
    }

    int peek()
    {
        if (isEmpty())
            return -1;

        return top->data;
    }

    int size()
    {
        Node *temp = top;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
};