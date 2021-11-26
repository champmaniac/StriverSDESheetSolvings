// Brute Force 
// TC O(N) SC O(1)
Node *findMiddle(Node *head) {
    Node* temp = head;
    int n =0;
    while(temp)
    {
        n++;
        temp=temp->next;
    }
    temp = head;
    for(int i=0;i<n/2;i++)
    {
        temp=temp->next;
    }
    return temp;
}


// Optimized way to solve is Two pointers approach 
// Tortoise-Hare-Approach
// TC O(N) SC O(1)
Node *findMiddle(Node *head) {
    Node* slow = head, *fast =head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow= slow->next;
        fast=fast->next->next;
    }
    return slow;
}