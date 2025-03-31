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

ll mod;
ll fact[N + 5], inv[N + 5];

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

ll lucas_theorem(ll n, ll k){
    if (k == 0) return 1;
    return 1LL*C(n % mod, k % mod)*lucas_theorem(n/mod, k/mod) % mod;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    int numTest;    cin >> numTest;
    cin >> mod;
    fact[0] = 1;
    for (int i=1;i< mod;i++ )
        fact[i] = (1LL*fact[i - 1]*i) % mod;
    inv[mod - 1] = binaryExpo(fact[mod - 1], mod - 2);
    for (int i=mod - 1;i>= 1;i-- )
        inv[i - 1] = (1LL*inv[i]*i) % mod;

    while (numTest-- ){
        ll n;   cin >> n;
        cout << lucas_theorem(2*n - 1, n) << '\n';
    }
}