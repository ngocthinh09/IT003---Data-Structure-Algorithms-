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
const int N = 2e5;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    priority_queue<ll,vector<ll>, greater<ll>>  Q;
    int n;  cin >> n;
    ll S;   cin >> S;
    for (int i=1;i<= n;i++ ){
        ll x;   cin >> x;
        Q.push(x);
    }
    ll res = 0;
    while (Q.size() >= 2){
        ll x1 = Q.top();    Q.pop();
        ll x2 = Q.top();    Q.pop();
        res += (x1 + x2);
        Q.push(x1 + x2);
    }
    cout << res;
}