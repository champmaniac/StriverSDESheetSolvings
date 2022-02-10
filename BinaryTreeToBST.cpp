class Solution{
public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder(Node* root,vector<int> &ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    void solve(Node* root,vector<int> &ans,int &i){
        if(i>=ans.size() || root==NULL) return;
        solve(root->left,ans,i);
        root->data=ans[i++];
        solve(root->right,ans,i);
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> ans;
        inorder(root,ans);
        int i=0;
        sort(ans.begin(),ans.end());
        solve(root,ans,i);
        return root;
    }
};