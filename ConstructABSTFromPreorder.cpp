class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
    TreeNode* build(vector<int>& preorder, int &i, int bound){
        if(preorder.size()==i || preorder[i]>bound) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder,i,root->val);
        root->right = build(preorder,i,bound);
        return root;
    }
};

// Alternate method

Node* construct(int pre[],char preLN[],int n,int &i){
    if(i>=n) return NULL;
    Node* root= new Node(pre[i]);
    if(preLN[i]=='N'){
        i++;
        root->left = construct(pre,preLN,n,i);
        i++;
        root->right=construct(pre,preLN,n,i);
    }
    return root;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int i=0;
    return construct(pre,preLN,n,i);
}