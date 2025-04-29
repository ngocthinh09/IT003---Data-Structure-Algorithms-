#include <bits/stdc++.h>
#define problem "test"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) (v).resize(unique(ALL(v)) - (v).begin())
#define BIT(x,i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
using namespace std;

class Node{
    public:
        int data;
        Node* _left;
        Node* _right;

        Node (int _data=0){
            data = _data;
            _left = nullptr;
            _right = nullptr;
        }
};

class BST{
    public:
        Node* root;
        
        BST (){
            root = nullptr;
        }

        Node* insert(int data){
            if (root == nullptr){
                root = new Node(data);
                return root;
            }
            
            Node* current = root;
            while (current){
                if (current->data < data){
                    if (current->_right){
                        current = current->_right;
                    }
                    else{
                        current->_right = new Node(data);
                        break;
                    }
                }
                else{
                    if (current->_left){
                        current = current->_left;
                    }
                    else{
                        current->_left = new Node(data);
                        break;
                    }
                }
            }
            return root;
        }
};

map<int,int> top_view;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    int n;  cin >> n;
    BST tree;
    for (int i=1;i<= n;i++ ){
        int x;  cin >> x;
        tree.insert(x);
    }

    Node* root = tree.root;
    
    queue<pair<Node*,int>> Q;
    Q.push({root, 0});
    while (!Q.empty()){
        Node* current = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();
        if (top_view.find(cnt) == top_view.end())
            top_view[cnt] = current->data;
        if (current->_right)
            Q.push({current->_right, cnt + 1});
        if (current->_left)
            Q.push({current->_left, cnt - 1});
    }

    vector<int> value;
    for (pii it : top_view)
        value.emplace_back(it.second);

    sort(ALL(value));
    for (int it : value)
        cout << it << ' ';
}