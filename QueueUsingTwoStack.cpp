// Queue using two stack
// TC O(N*T) SC O(1) Costly enQueue TC O(N) all other are O(1)

#include<stack>
class Queue {
    // Define the data members(if any) here.
    stack<int>*s1;
    stack<int>*s2;
    public:
    Queue() {
        // Initialize your data structure here.
        s1 = new stack<int>();
        s2 = new stack<int>();
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        // Moving all elements from s1 to s2
        while(!s1->empty()){
            // To insert a value,first whole of the s1 is transfered to s2 and then new element is inserted in s1
            s2->push(s1->top());
            s1->pop();
        }
        // pushing the value in s1
        s1->push(val);

        //pushing everythin back in s1
        while(!s2->empty()){
            s1->push(s2->top());
            s2->pop();
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
        // If first stack is empty
        if(s1->empty())
            return -1;
        // Return top of s1
        int tp = s1->top();
        s1->pop();
        return tp;
    }

    int peek() {
        // Implement the peek() function here.
        // Returning the front element of the queue
        if(s1->empty())
            return -1;
        return s1->top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        // Whether the queue is empty or not.
        return (s1->empty());
    }
};