// Queue Approach
// TC O(N) SC O(N)
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> res;
    if(root==NULL) return res;
    queue<BinaryTreeNode<int>*> nodesQueue;
    nodesQueue.push(root);
    bool LeftToRight=false;

    while(!nodesQueue.empty()){
        int size = nodesQueue.size();
        vector<int> row;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* node = nodesQueue.front();
            nodesQueue.pop();
            row.push_back(node->data);
            if(node->left)
                nodesQueue.push(node->left);
            if(node->right)
                nodesQueue.push(node->right);
        }
        for(int i=0;i<size;i++){
            if(LeftToRight==false)
                res.push_back(row[i]);
            else
                res.push_back(row[size-i-1]);
        }
        LeftToRight^=1;
    } 
    return res;
}
