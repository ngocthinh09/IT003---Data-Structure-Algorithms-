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
const char dx[] = {'{', '}', '(', ')', '[', ']'};

bool validChar(char x){
    for (char i : dx)
        if (i == x)
            return true;
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    string str; cin >> str;
    stack<char> mys;
    while (!mys.empty())    mys.pop();

    for (int i=0;i< (int)str.length();i++ ){
        if (!validChar(str[i])) continue;
        if (str[i] == dx[0] || str[i] == dx[2] || str[i] == dx[4])
            mys.push(str[i]);
        else{
            if (str[i] == '}'){
                if (mys.empty() || mys.top() != '{')
                    return void(cout << 0), 0;
                else mys.pop();
            }
            else if (str[i] == ')'){
                if (mys.empty() || mys.top() != '(')
                    return void(cout << 0), 0;
                else mys.pop();
            }
            else if (str[i] == ']'){
                if (mys.empty() || mys.top() != '[')
                    return void(cout << 0), 0;
                else mys.pop();
            }
        }
    }

    if (mys.empty())    cout << 1;
    else cout << 0;
}