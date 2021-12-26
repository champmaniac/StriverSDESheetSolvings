// Using two stacks
// TC O(1) for all operations SC O(Q) Q -- Number of queries

#include <stack>

class MaxStack{
public:
    // Initialize MaxStack.
    stack<int> normalStack;
    stack<int> maxStack;
    MaxStack() {}

    void specialPush(int value){
        // Push the value in the normal stack.
        normalStack.push(value);
        // If the value is also the biggest value then push it into the max stack.
        if (maxStack.empty() || maxStack.top() <= value){
            maxStack.push(value);
        }
    }

    // Return the popped element.
    int specialPop(){

        // Check whether stack is empty.
        if (normalStack.empty()){
            return -1;
        }

        // If the top element in the normal stack is also the biggest element then pop that from max stack also.
        if (normalStack.top() == maxStack.top()){
            maxStack.pop();
        }

        // Return the value at top of normal stack.
        int value = normalStack.top();
        normalStack.pop();
        return value;
    }

    // Return value at the top of stack.
    int specialTop(){

        // Check whether stack is empty.
        if (normalStack.empty()){
            return -1;
        }

        // Return the top element of normal stack.
        return normalStack.top();
    }

    // Return maximum value in stack.
    int specialMax(){

        // Check whether stack is empty.
        if (normalStack.empty()){
            return -1;
        }

        // Return the biggest element, that is the element at the top of max stack.
        return maxStack.top();
    }
};