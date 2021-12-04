// Stack using two queues
#include <bits/stdc++.h>
class Stack {
   public:
    queue<int>*q;
    //Constructor
    Stack() {
        q = new queue<int>();
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q->size();
    }

    bool isEmpty() {
        return getSize()==0;
    }

    void push(int data) {
        // Get the size of the queue
        int size = q->size();
        // Enqueue the new data to the queue
        q->push(data);
        // Make the new data front of the queue
        for(int i=0;i<size;i++)
        {
            q->push(q->front());
            q->pop();
        }
    }

    int pop() {
        if(isEmpty())
            return -1;

        int ans=q->front();
        q->pop();
        return ans;
    }

    int top() {
        if(isEmpty())
            return -1;

        int ans=q->front();
        return ans;
    }
};