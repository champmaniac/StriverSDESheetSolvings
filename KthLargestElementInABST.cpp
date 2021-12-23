// Time Optimized using Inorder
// TC O(N) SC O(N)
class Solution
{
    public:
    void inOrder(Node* root,vector<int>&res){
        if(root==NULL) return;
        inOrder(root->left,res);
        res.push_back(root->data);
        inOrder(root->right,res);
    }
    int kthLargest(Node* root, int k) {
        vector<int> res;
        inOrder(root,res);
        int n = res.size();
        return res[n-k];
    }
};