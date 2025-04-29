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
        int freq;
        char ch;
        Node* left;
        Node* right;

        Node (int _freq = 0, char _ch = ' '){
            this->freq = _freq;
            this->ch = _ch;
            this->left = nullptr;
            this->right = nullptr;
        }

        bool operator < (const Node &other) const{
            return freq > other.freq;
        }
};


struct CompareNode{
    bool operator() (Node* lhs, Node* rhs){
        return lhs->freq > rhs->freq;
    }
};

int n;
string str;
int freqChar[257];
map<char, int> getID;
map<int, char> getChar;

string compress[257];

int CharToID(char ch){
    if (getID.find(ch) == getID.end()){
        getID[ch] = (int)getID.size();
        getChar[getID[ch]] = ch;
    }
    return getID[ch];
}

char IDToChar(int id){
    return getChar[id];
}

void dfs(Node* root, string current=""){
    if (root->ch != ' '){
        int id = CharToID(root->ch);
        compress[id] = current;
        return;
    }
    if (root->left != nullptr)
        dfs(root->left, current + "0");
    if (root->right != nullptr)
        dfs(root->right, current + "1");
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n >> str;
    for (int i=0;i< n;i++ )
        freqChar[CharToID(str[i])]++;

    priority_queue<Node*, vector<Node*>, CompareNode> Q;
    while (!Q.empty())  Q.pop();

    for (int i=0;i<= 256;i++ ){
        if (freqChar[i] == 0)   continue;
        Node* newNode = new Node(freqChar[i], IDToChar(i));
        Q.push(newNode);
    }

    if ((int)Q.size() == 1){
        cout << n;
        return 0;
    }

    while (Q.size() > 1){
        Node* _left = Q.top();      Q.pop();
        Node* _right = Q.top();     Q.pop();
        Node* newNode = new Node(_left->freq + _right->freq);
        newNode->left = _left;
        newNode->right = _right;
        Q.push(newNode);
    }

    Node* root = Q.top();
    dfs(root);

    ll res = 0;
    for (int i=0;i<= 256;i++ ){
        res += 1LL*freqChar[i]*compress[i].length();
    }

    cout << res;
}