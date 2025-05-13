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
const int N = 5e5;

int n;
ll a[N + 5];

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
    ll res = 0;
    for (int i=1, j=1;i<= n;i++ ){
        while (j < n && a[j + 1] == a[i])
            j++;
        int p = upper_bound(&a[j+1], &a[n+1], 2*a[i] - 1) - &a[0] - 1;
        res += 1LL*(j - i + 1)*(j - i)*(i-1)/2;
        res += 1LL*(j - i + 1)*(j - i)*(j - i - 1)/6;
        if (p > j)
            res += 1LL*(j - i + 1)*(j - i)*(p - j)/2;
        i = j;
    }
    cout << res;
}