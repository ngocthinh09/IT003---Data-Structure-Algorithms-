void inOrder(Node* root){
    if (!root)
        return;
    if (root->left)
        inOrder(root->left);
    cout << root->data << ' ';
    if (root->right)
        inOrder(root->right);
}