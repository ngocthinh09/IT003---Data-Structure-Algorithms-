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

ll n, k, p, q;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    if (fopen(problem".inp","r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n >> k >> p >> q;
    ll cur = (2*(p - 1) + q);
    ll _prev = (cur - k);

    ll _next = (cur + k);

    if ((_prev < 1 && _next > n))   cout << -1;
    else{
        if (_prev >= 1){
            cout <<((_prev + 1)/2)<<' '<<((_prev % 2) != 0 ? 1:2);
        }
        else{
            cout <<((_next + 1)/2)<<' '<<((_next % 2) != 0 ? 1:2);
        }
    }

}