#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

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

class myQueue
{

public:
    Node *front;
    Node *rear;
    int size1;

    myQueue()
    {
        front = rear = NULL;
        size1 = 0;
    }

    bool isEmpty()
    {
        return size1 == 0;
    }

    void enqueue(int x)
    {
        Node *temp = new Node(x);
        if (isEmpty())
            front = rear = temp;
        else
        {
            rear->next = temp;
            rear = temp;
        }
        size1++;
    }

    void dequeue()
    {
        if (isEmpty())
            return;

        Node *temp = front;
        front = front->next;

        // Agar front NULL ho gaya, matlab queue khali ho gayi
        // toh rear ko bhi NULL karo
        if (front == NULL)
        {
            rear = NULL;
        }

        delete (temp);
        size1--;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;

        return front->data;
    }

    int size()
    {
        return size1;
    }
};