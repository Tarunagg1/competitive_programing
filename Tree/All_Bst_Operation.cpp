
struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

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

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* constructBstPreorder(int preorder[],int* preorderidx,int key,int min,int max,int n){
    if(*preorderidx >= n){
        return NULL;
    }

    Node* root = NULL;
    if(key > min && key < max){
        root = new Node(key);
        *preorderidx = *preorderidx + 1;
        if(*preorderidx < n){
            root->left = constructBstPreorder(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        }
        if(*preorderidx < n){
            root->right = constructBstPreorder(preorder,preorderidx,preorder[*preorderidx],key,max,n);
        }
    }
    return root;
}

Node* searchInBst(Node *root,int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        return root;
    }else if(root->data > val){
        return searchInBst(root->left,val);
    }else{
        return searchInBst(root->right,val);
    }
}

Node* inorderSuccessor(Node *root){
    Node *curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node* deleteInBst(Node *root,int val){
    if(root == NULL){
        return NULL;
    }
    if(val < root->data){
        root->left = deleteInBst(root->left,val);
    }else if(val > root->data){
        root->right = deleteInBst(root->right,val);
    }
    else{
        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // case 3
        Node* temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteInBst(root->right,temp->data);
    }
    return root;

}


int main(){
    Node *root = NULL;
    root = insertbst(root,5);
    insertbst(root,1);
    insertbst(root,3);
    insertbst(root,4);
    insertbst(root,2);
    insertbst(root,7);
    //inorder(root);
    /* if(searchInBst(root,55) == NULL){
        cout<<"not exist"<<endl;
    }else{
        cout<<"exist";
    } */
    inorder(root);
    cout<<endl;
    root = deleteInBst(root,7648);
    inorder(root);
}

