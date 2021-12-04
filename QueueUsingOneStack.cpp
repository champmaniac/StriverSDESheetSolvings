// Queue using One stack
// TC O(N*T) SC O(N) Costly deQueue and Peek TC O(N) all other are O(1)

#include<stack>
class Queue {
    // Define the data members(if any) here.
    stack<int>*st;
    public:
    Queue() {
        // Only one user stack is used
        st = new stack<int>();
    }

    void enQueue(int val) {
        // push the value to the stack
        st->push(val);
    }

    int deQueue() {
        if(st->empty())
            return -1;

        // Pop the current top element
        int x = st->top();
        st.pop();

        //base case of the recursion
        if(st->empty()){
            return x;
        }

        //Recursively pop the next element
        int nxt = deQueue();
        st->push(x);
        return nxt;
    }

    int peek() {
        if(st->empty())
            return -1;
        int x = st->top();
        st->pop();
        if(st->empty()){
            st->push(x);
            return x;
        }
        int nxt =peek();
        st->push(x);
        return nxt;
    }

    bool isEmpty() {
        return (st->empty());
    }
};