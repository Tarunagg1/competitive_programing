Node* insertbst(Node *root,int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertbst(root->left,val);
    }else{
        root->right = insertbst(root->right,val);
    }
    return root;
}
