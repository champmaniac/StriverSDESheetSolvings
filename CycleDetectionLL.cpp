// Brute Force 
// TC O(N*N) SC O(1)



// Optimized using hashmap 
// TC O(N) SC O(N)
#include<unordered_set>
bool detectCycle(Node *head)
{
	//	Write your code here
	unordered_set<Node*> st;
	while(head!=NULL){
		if(st.find(head)!=st.end())
			return true;
		st.insert(head);
		head = head->next;
	}
	return false;
}

// More Optmized 
// TC O(N) SC O(1)