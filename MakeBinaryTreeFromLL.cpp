void convert(Node *head, TreeNode *&root) {
    // Your code here
    if(!head)return;
    root=new TreeNode(head->data);
    convert(head->next,root->left);
}