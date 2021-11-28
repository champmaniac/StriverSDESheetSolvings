// Best Optimized 
// TC O(N) SC(1)
Node *firstNode(Node *head)
{
	//    Write your code here.
	if(head ==NULL || head->next==NULL)
		return NULL;

	Node* slow = head;
	Node* fast = head;
	Node* entry= head;

	while(fast->next && fast->next->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
			while(slow!=entry)
			{
				slow=slow->next;
				entry=entry->next;
			}
			return entry;
		}
	}
	return NULL;
}