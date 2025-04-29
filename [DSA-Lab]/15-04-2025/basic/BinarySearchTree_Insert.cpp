Node* insert(Node* root, int data){
    if (!root){
        root = new Node(data);
        return root;
    }
    
    if (root->data < data){
        if (root->right)
            insert(root->right, data);
        else root->right = new Node(data);
    }
    
    if (root->data > data){
        if (root->left)
            insert(root->left, data);
        else root->left = new Node(data);
    }
    
    return root;
}