// BFS Traversal
// TC O(h) SC O(1)
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ceil =-1;
    while(node){
        if(node->data==x)
        {
            ceil = node->data;
            return ceil;
        }
        if(x>node->data){
            node = node->right;
        }
        else
        {
            ceil = node->data;
            node = node->left;
        }
    }
    return ceil;
}