// Stack using two queues
#include <bits/stdc++.h>
class Stack {
   public:
    queue<int>*q1,*q2;
    //Constructor
    Stack() {
        q1 = new queue<int>();
        q2 = new queue<int>(); 
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1->size();
    }

    bool isEmpty() {
        return getSize()==0;
    }

    void push(int data) {
        // Enqueue new element to q2
        q2->push(data);

        // Enqueue all the elements of q1 into q2
        while(q1->size()>0)
        {
            q2->push(q1->front());
            q1->pop();
        }

        // swap q1 and q2
        queue<int>* temp = q1;
        q1=q2;
        q2=temp;
    }

    int pop() {
        //if empty return -1
        if(isEmpty())
            return -1;
        //simpy dequeue from the queue q1
        int ans = q1->front();
        q1->pop();
        return ans;
    }

    int top() {
        if(isEmpty())
            return -1;

        int ans = q1->front();
        return ans;
    }
};