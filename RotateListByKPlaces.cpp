// Brute Solution TC O(Number of nodes present in the list*k) SC O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        for(int i=0;i<k;i++){
            ListNode* temp = head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            ListNode* end= temp->next;
            temp->next=NULL;
            end->next=head;
            head=end;
        }
        return head;
    }
};

// Optimal Solution TC O(length of list) + O(length of list – (length of list%k)) SC O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL||k==0) return head;
        ListNode* temp = head;
        int length=1;
        while(temp->next!=NULL){
            ++length;
            temp=temp->next;
        }   
        // linking the last node to the head;
        temp->next=head;
        k=k%length;//when k is more than length of list
        int end=length-k;// to get the end of the list
        while(end--){
            temp=temp->next;
        }
        //breaking last node link and pointing to NULL
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};