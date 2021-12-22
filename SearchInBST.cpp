// Best Approach
// TC (H) SC O(1)
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int> * ptr = root;
    while(ptr!=NULL){
        if(ptr->data==x)
            return true;
        else if(ptr->data>x)
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    return false;
}