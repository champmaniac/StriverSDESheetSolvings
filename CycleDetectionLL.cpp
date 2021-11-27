// Brute Force 
// TC O(N*N) SC O(1)
bool detectCycle(Node *head)
{
	int numberOfNodesPassed = 0;
	Node* outerLoopNode = head;

	while(outerLoopNode!=NULL)
	{
		numberOfNodesPassed++;
		outerLoopNode=outerLoopNode->next;
		Node* innerLoopNode = head;
		int countInnerLoop = numberOfNodesPassed;
		while(countInnerLoop--)
		{
			if(outerLoopNode==innerLoopNode)
				return true;
			innerLoopNode=innerLoopNode->next;
		}
	}
}


// Optimized using hashset 
// TC O(N) SC O(N)
#include<unordered_set>
bool detectCycle(Node *head)
{
	//	Write your code here
	unordered_set<Node*> st;
	while(head!=NULL){
		// We reached some earlier node again thus we found a cycle
		if(st.find(head)!=st.end())
			return true;
		// Add the node to the hashset of already seen nodes
		st.insert(head);
		head = head->next;
	}
	// we did'nt found any cycle
	return false;
}

// More Optmized 
// TC O(N) SC O(1)

bool detectCycle(Node *head)
{
	if(head ==NULL || head->next ==NULL)
		return false;
	//  Slow Pointer - This will be incremented by 1 Nodes.
	Node* slow = head;
	// //  Fast Pointer - This will be incremented by 2 Nodes.
	Node* fast = head->next;

	while(slow!=fast)
	{
		// We reached the end of the List and haven't found any cycle
		if(fast ==NULL || fast->next==NULL)
			return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	// we found a cycle
	return true;
}