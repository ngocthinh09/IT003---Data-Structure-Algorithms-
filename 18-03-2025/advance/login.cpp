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

map<string, int> getID;

struct User{
    vector<string> password;
    User(){}
};
vector<User> database;

int findID(const string &str){
    if (getID.find(str) == getID.end()){
        int sz = (int)getID.size();
        getID[str] = sz;
        database.emplace_back(User());
    }
    return getID[str];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    int n, q;   cin >> n >> q;
    for (int i=1;i<= n;i++ ){
        string str;     cin >> str;
        int id = findID(str);
        string pass;    cin >> pass;
        database[id].password.push_back(pass);
    }

    for (int i=1;i<= q;i++ ){
        string name;    cin >> name;
        if (getID.find(name) == getID.end())
            cout << "Chua Dang Ky!\n";
        else{
            int id = getID[name];
            for (string pass : database[id].password)
                cout << pass << ' ';
            cout << '\n';
        }
    }
}