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

int n, m;
int a[N + 5];
int _left[N + 5], _right[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n >> m;
    for (int i=1;i<= n;i++ ){
        (i != n ? _left[i] = i + 1 : _left[i] = 1);
        (i != 1 ? _right[i] = i - 1 : _right[i] = n);
    }

    for (int i=1;i<= m;i++ ){
        int x, y;   cin >> x >> y;
        _left[_right[x]] = _left[x];
        _right[_left[x]] = _right[x];

        _left[x] = _left[y];
        _right[_left[y]] = x;    
        _left[y] = x;

        _right[x] = y;
    }

    int u = 1;
    do{
        cout << u << ' ';
        u = _left[u];
    }
    while (u != 1);
}