// Brute Force using Stack 
// TC O(N) SC O(N)
#include<stack>
bool isPalindrome(LinkedListNode<int> *head) {
    stack<int> st;
    LinkedListNode<int> * temp = head;

    while(temp!=NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    while(head!=NULL)
    {
        int top = st.top();
        st.pop();
        if(top!=head->data)
            return false;
        head=head->next;
    }
    return true;
}

// Optimized code by finding reverseLinkedList and Middle of LinkedList
// TC O(N) SC O(1)
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> * prev = NULL;
    LinkedListNode<int> * next = NULL;

    while(head!=NULL)
    {
        next = head->next;
        head->next=prev;
        prev=head;
        head = next;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL || head->next==NULL)
        return true;
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    // Finding the middle of the linkedlist
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // reversing from the slow->next i.e after the middle element
    slow->next = reverseLinkedList(slow->next);
    slow = slow->next;

    while(slow!=NULL)
    {
        if(head->data!=slow->data)
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;

}

