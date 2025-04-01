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
const int N = 1e5;

struct Trie{
    struct Node{
        Node *child[26];
        Node (){
            for (int i=0;i< 26;i++ )
                child[i] = NULL;
        }
    };

    int numNode;
    Node *root;
    Trie(){
        root = new Node();
    }

    void addString(const string &str){
        Node *p = root;
        for (int i=0;i< (int)str.length();i++ ){
            int id = str[i] - 'a';
            if (p->child[id] == NULL)   
                p->child[id] = new Node();
            p = p->child[id];
        }
    }

    bool checkStr(const string &str){
        Node *p = root;
        for (int i=0;i< (int)str.length();i++ ){
            int id = str[i] - 'a';
            if (p->child[id] == NULL)   
                return false;
            p = p->child[id];
        }
        return true;
    }
};

string str[N + 5];
set<string> mys;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    int n, m, q;    cin >> n >> m >> q;
    Trie trie = Trie();
    for (int i=1;i<= n;i++ )
        cin >> str[i];
    
    for (int i=1;i<= n;i++){
        for (int j=0;j< m;j++ ){
            string cur = "";
            for (int k=j;k < min(m, j + 10);k++ ){
                cur += str[i][k];
                if ((int)cur.length() == 8 || (m - k) <= 8)
                    trie.addString(cur);
                else if ((int)cur.length() > 8)
                    mys.insert(cur);
            }
        }
    }

    for (int j=0;j< m;j++ ){
        for (int i=1;i<= n;i++ ){
            string cur = "";
            for (int k=i;k <= min(n,i + 9);k++ ){
                cur += str[k][j];
                if ((int)cur.length() == 8 || (n - k + 1) <= 8)
                    trie.addString(cur);
                else if ((int)cur.length() > 8)
                    mys.insert(cur);
            }
        }
    }

    
    for (int i=1;i<= q;i++ ){
        string query;   cin >> query;
        if ((int)query.length() <= 8){
            cout << (trie.checkStr(query) ? 1 : 0);
        }
        else{
            cout << ((mys.find(query) != mys.end()) ? 1 : 0);
        }
    }

}