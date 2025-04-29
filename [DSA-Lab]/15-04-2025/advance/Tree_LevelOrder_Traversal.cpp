void levelOrder(Node* root){
    queue<Node*> Q;
    Q.push(root);
    while (!Q.empty()){
        cout<<Q.front()->data<<' ';
        if (Q.front()->left)
            Q.push(Q.front()->left);
        if (Q.front()->right)
            Q.push(Q.front()->right);
        Q.pop();
    }
}