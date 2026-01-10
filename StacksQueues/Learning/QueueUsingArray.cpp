#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// https://www.geeksforgeeks.org/problems/implement-queue-using-array/1

class myQueue
{

public:
    vector<int> arr;
    int front;
    int rear;
    int size;
    int capacity;

    myQueue(int n)
    {
        arr.resize(n);
        front = 0;
        rear = -1;
        size = 0;
        capacity = n;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void enqueue(int x)
    {
        if (isFull())
            return;

        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
            return;

        front = (front + 1) % capacity;
        size--;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;

        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;

        return arr[rear];
    }
};