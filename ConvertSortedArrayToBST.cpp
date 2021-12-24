// Recursive approach
// TC O(N) SC O(logN)
TreeNode<int>* helper(vector<int> &arr, int start,int end){
    if(end<=start)
        return NULL;
    int mid =(start+end)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = helper(arr,start,mid);
    root->right=helper(arr,mid+1,end);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return helper(arr,0,n);
}