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

int n;
ll a[N + 5];
ll prefix[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n;
    for (int i=1;i<= n;i++ )
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i=1;i<= n;i++ )
        prefix[i] = prefix[i-1] + a[i];
    ll res = 0;
    for (int i=1;i<= n;i++ )
        res += 1LL*(i-1)*a[i] - prefix[i-1];

    cout << res;
}