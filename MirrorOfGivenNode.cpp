class Solution
{
public:
    int res=-1;
    void helper(Node* r1, Node* r2, int target){
        if(!r1 || !r2) return;
        if(r1->data==target)
            res=r2->data;
        if(r2->data==target)
            res=r1->data;
        helper(r1->left,r2->right,target);
        helper(r1->right,r2->left,target);
    }
    int findMirror(Node *root, int target)
    {
        //code here
        res =-1;
        if(root->data==target)
            return root->data;
        helper(root->left,root->right,target);
        return res;
    }
};