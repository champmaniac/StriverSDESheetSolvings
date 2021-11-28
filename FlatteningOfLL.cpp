// Using MergingLists (In Place)
// TC O(N*K) SC O(N)
Node* mergeTwoLists(Node* a, Node* b)
{
	if(a==NULL) return b;
	if(b==NULL) return a;

	Node* merged =NULL;
	if(a->data<b->data)
	{
		merged=a;
		merged->child=mergeTwoLists(a->child,b);
	}
	else
	{
		merged=b;
		merged->child=mergeTwoLists(a,b->child);
	}

	merged->next=NULL;
	return merged;
}


Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	// recur for list on right
	head->next =flattenLinkedList(head->next);
	// now merge
	head = mergeTwoLists(head,head->next);
	return head;
}
