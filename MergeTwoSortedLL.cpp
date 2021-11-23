// Best Solution TC O(N)

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* mergeTwoLists(Node<int>* first, Node<int>* second)
{
   N if(first==NULL) return second;
    if(second==NULL) return first;
    if(first->data < second->data)
    {
        first->next = mergeTwoLists(first->next,second);
        return first;
    }
    else
    {
        second->next = mergeTwoLists(first,second->next);
        return second;
    }
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    return mergeTwoLists(first,second);       
}

