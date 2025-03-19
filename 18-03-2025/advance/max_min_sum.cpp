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
const ll mod = 1e9 + 7;

ll fact[N + 5], inv[N + 5];
ll arr[N + 5];

ll binaryExpo(ll x, ll y){
    ll res = 1;
    for (;y > 0;y >>= 1){
        if (y & 1)  res = (res * x) % mod;
        x = (x * x) % mod;
    }
    return res;
}

ll C(int n, int k){
    if (k > n)  return 0;
    if (k == 0 || n == k)   return 1;
    return ((1LL*((1LL*fact[n]*inv[k])%mod)*inv[n - k]) % mod);
}

int n, k;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n >> k;
    for (int i=1;i<= n;i++ )    cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    
    fact[0] = 1;
    for (int i=1;i<= N;i++ )
        fact[i] = (1LL*fact[i - 1]*i) % mod;
    inv[N] = binaryExpo(fact[N], mod - 2);
    for (int i=N;i>= 1;i-- )
        inv[i - 1] = (1LL*inv[i]*i) % mod;

    ll res = 0;
    for (int i=1;i<= n;i++ ){
        if (i >= k)
            res = (res + 1LL*C(i - 1, k - 1)*arr[i]) % mod;
        if (i <= n - k + 1)
            res = (res - 1LL*C(n - i, k - 1)*arr[i]) % mod;
    }

    cout << (res + mod) % mod;
}