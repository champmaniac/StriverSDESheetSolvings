// Brute and the best way to solve is Two pointers approach
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