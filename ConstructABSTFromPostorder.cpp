Node* build(int post[],int l,int h){
    if(l>h) return NULL;
    else if(l==h){
        Node* root = new Node(post[l]);
        return root;
    }
    else
    {
        int mid = (l+h)/2;
        Node* root = new Node(post[mid]);
        root->left = build(post,l,mid-1);
        root->right=build(post,mid+1,h);
        return root;
    }
}
Node *constructTree (int post[], int size)
{
//code here
    sort(post,post+size);
    return build(post,0,size-1);
}