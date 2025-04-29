int height(Node* root){
    int maxHeight = 0;
    if (root->left)
        maxHeight = max(maxHeight, height(root->left));
    if (root->right)
        maxHeight = max(maxHeight, height(root->right));
        
    return maxHeight + 1;
}