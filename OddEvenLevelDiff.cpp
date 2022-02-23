class Solution{
  public:
    /*You are required to complete this function*/
    void solve(Node* root,int &even,int &odd, int level){
        if(!root) return;
        if(level%2==0) even+=root->data;
        else odd+=root->data;
        
        solve(root->left,even,odd,level+1);
        solve(root->right,even,odd,level+1);
    }
    int getLevelDiff(Node *root)
    {
       //Your code here
       int even=0,odd=0;
       solve(root,even,odd,1);
       return odd-even;
    }
};