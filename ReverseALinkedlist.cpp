// Brute Force TC O(N^2) SC O(N)
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    if(head ==NULL || head->next ==NULL)
    {
        return head;
    }

    LinkedListNode<int> * newHead = reverseLinkedList(head->next);
    LinkedListNode<int> * temp = head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    head->next=NULL;
    temp->next =head;

    return newHead;
}

// Little Optimized using recursion TC O(N) SC O(N)
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head==NULL || head->next ==NULL)
    {
        return head;
    }
    LinkedListNode<int> *newHead = reverseLinkedList(haed->next);
    head->next->next =head;
    head->next = NULL;
    return newHead;
}

// Most Optimzed using Three pointer approach TC O(N) SC O(1)
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    LinkedListNode<int> * prev = NULL;
    LinkedListNode<int> * current = head;

    while(current!=NULL)
    {
        LinkedListNode<int> * newNode = current->next;
        current->next = prev;
        prev = current;
        current=newNode;
    }

    return prev;
}