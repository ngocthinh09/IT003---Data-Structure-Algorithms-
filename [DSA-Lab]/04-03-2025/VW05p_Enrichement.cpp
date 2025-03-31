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

int n, m;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    // freopen(problem".inp","r",stdin);
    // freopen(problem".out","w",stdout);
    cin >> n >> m;
    vector<vector<ll>> prefix(n + 1, vector<ll> (m + 1, 0));
    for (int i=1;i<= n;i++ )
        for (int j=1;j<= m;j++ ){
            cin >> prefix[i][j];
            prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }

    ll res = 4e18;
    for (int i=1;i<= n - 2;i++ )
        for (int j=1;j<= m - 2;j++ ){
            int u = i + 2, v = j + 2;
            res = min(res, prefix[u][v] - prefix[u][j - 1] - prefix[i - 1][v] + prefix[i - 1][j - 1]);
        }

    cout << res;
}