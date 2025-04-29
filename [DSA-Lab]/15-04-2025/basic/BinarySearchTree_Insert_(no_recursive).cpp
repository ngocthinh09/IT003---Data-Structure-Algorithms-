Node *insert(Node* root, int data){
    Node* current = root;

    if (root == nullptr){
        root = new Node(data);
        return root;
    }
    
    while (current){
        if (current->data < data){
            if (current->right){
                current = current->right;
            }
            else{
                current->right = new Node(data);
                break;
            }
        }
        else if (current->data > data){
            if (current->left){
                current = current->left;
            }
            else{
                current->left = new Node(data);
                break;
            }
        }
        else break;
    }
    return root;
}