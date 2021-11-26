// Brute Force TC O(1) SC O(1)
void deleteNode(LinkedListNode<int> * node) {
	// create a temp pointer that initially points to node->next
	LinkedListNode<int> * temp = node->next;
	// Here nodes data is pointing to temp data and making node->next to temp->next
	node->data = temp->data;
	node->next=temp->next;
	// finally deleting temp pointer
	delete temp;
}