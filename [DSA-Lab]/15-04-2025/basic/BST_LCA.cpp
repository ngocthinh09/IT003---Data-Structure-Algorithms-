Node* LCA(Node* root, int v1, int v2){
    if (v1 > root->data && v2 > root->data)
        return LCA(root->right, v1, v2);
    
    if (v1 < root->data && v2 < root->data)
        return LCA(root->left, v1, v2);
    return root;
}