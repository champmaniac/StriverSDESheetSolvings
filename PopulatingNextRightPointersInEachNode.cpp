class Solution {
public:
    Node* connect(Node* root) {
        Node* LeftNode = root;
        while(LeftNode !=NULL && LeftNode->left!=NULL){
            populateLowerLevel(LeftNode);
            LeftNode=LeftNode->left;
        }
        return root;
    }
private:
    void populateLowerLevel(Node* startNode){
        Node *iter = startNode;
        while(iter!=NULL){
            iter->left->next=iter->right;
            if(iter->next!=NULL)
                iter->right->next=iter->next->left;
            iter=iter->next;
        }
    }
};