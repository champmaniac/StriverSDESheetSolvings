// Brute Force
// TC O(N)+O(nlogn) SC O(N)
class Solution {
public:
    void preOrder(TreeNode* root,vector<int>&res){
        if(root==NULL) return;
        res.push_back(root->val);
        preOrder(root->left,res);
        preOrder(root->right,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        preOrder(root,res);
        sort(res.begin(),res.end());
        return res[k-1];
    }
};