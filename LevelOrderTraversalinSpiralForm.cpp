int height(Node* root){
    if(!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1+max(lh,rh);
}
void solve(Node* root,int level,vector<int>&ans,int counter){
    if(!root)return;
    if(level==1) ans.push_back(root->data);
    else if(counter%2!=0){
        solve(root->left,level-1,ans,counter);
        solve(root->right,level-1,ans,counter);
    }
    else
    {
        solve(root->right,level-1,ans,counter);
        solve(root->left,level-1,ans,counter);
    }
}
//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    int n =height(root);
    int counter=0;
    for(int i=1;i<=n;i++){
        solve(root,i,ans,counter);
        counter++;
    }
    return ans;
}