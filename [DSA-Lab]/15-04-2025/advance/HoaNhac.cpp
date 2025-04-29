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

stack<pii> S;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    int n;  cin >> n;
    ll res = 0;
    for (int i=1;i<= n;i++ ){
        int x;  cin >> x;
        if (S.empty())
            S.push({x, 1});
        else{
            pii newP = {x, 1};
            while (!S.empty() && S.top().fi <= newP.fi){
                res += (ll)S.top().se;
                if (S.top().fi == newP.fi)
                    newP.se += S.top().se;
                S.pop();
            }
            if (!S.empty())
                res++;
            S.push(newP);
        }
    }

    cout << res;
}