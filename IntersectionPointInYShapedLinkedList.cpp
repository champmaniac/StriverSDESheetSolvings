// Better Approach using hashing
// TC - O(N+M) SC O(1)
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_map<Node*,bool>mp;
    while(head1){
        mp[head1]=true;
        head1=head1->next;
    }
    while(head2){
        if(mp[head2])
            return head2->data;
        head2=head2->next;
    }
    return -1;
}

