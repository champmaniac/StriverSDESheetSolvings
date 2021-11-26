// Optimzed way by slow and fast pointers 
// TC O(N) SC (1)
LinkedListNode<int> *removeKthNode(LinkedListNode<int> *head, int K){
    if(head==NULL || K ==0)
        return head;
    LinkedListNode<int> *slow =head;
    LinkedListNode<int> *fast =head;

    for(int i =0;i<K;i++)
    {
        // If head is the kth node from end of LL
        if(fast->next==NULL)
        {
            LinkedListNode<int> *next = head->next;
            head->next=NULL;
            head=next;
            return head;
        }
        else
            fast = fast->next;
    }

    // Moving both slow and fast pointers at same speed
    while(fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Removing the Kth node from end of the LL
    slow->next = slow->next->next;

    return head;
}