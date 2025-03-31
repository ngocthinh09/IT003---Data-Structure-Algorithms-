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

ll n, x;
ll a[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    // freopen(problem".inp","r",stdin);
    // freopen(problem".out","w",stdout);
    cin >> n >> x;
    for (int i=1;i<= n;i++ )    cin >> a[i];
    
    sort(a + 1, a + n + 1);

    ll res = 0;
    a[n + 1] = (int)1e9;
    for (int i=1;i<= n;i++ ){
        int p = upper_bound(a + i + 1, a + n + 1, x - a[i]) - &a[0] - 1;
        if (i < p && a[i] + a[p] <= x){
            res = max(res, a[i] + a[p]);
        }
    }

    cout << res;
}