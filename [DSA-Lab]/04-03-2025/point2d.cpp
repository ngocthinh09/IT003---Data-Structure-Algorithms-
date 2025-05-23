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

const int N = 1e6;
int n;
pii a[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    // freopen(problem".inp","r",stdin);
    // freopen(problem".out","w",stdout);
    cin >> n;
    for (int i=1;i<= n;i++ )
        cin >> a[i].fi >> a[i].se;

    sort(a + 1, a + n + 1, [&](pii l, pii r){
        return ((l.fi == r.fi) ? l.se > r.se : l.fi < r.fi);
    });

    for (int i=1;i<= n;i++ )
        cout << a[i].fi << ' ' << a[i].se << '\n';
}