void postOrder(Node* root){
    stack<pair<Node*, int>> myS;
    while (!myS.empty())    myS.pop();

    myS.push({root, 0});

    while (!myS.empty()){
        Node* current = myS.top().first;
        int state = myS.top().second;
        myS.pop();
        
        if (state == 0){
            myS.push({current, 1});
            if (current->left)
                myS.push({current->left, 0});
        }
        else if (state == 1){
            myS.push({current, 2});
            if (current->right)
                myS.push({current->right, 0});
        }
        else if (state == 2)
            cout << current->data << ' ';
    }
}