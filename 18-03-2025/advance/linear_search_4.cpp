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

int numTest;
map<int, int> cnt;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> numTest;
    while (numTest-- ){
        int n, k;  cin >> n >> k;
        for (int i=1;i<= n;i++ ){
            int x;  cin >> x;
            cnt[x]++;
        }
        int type_1 = 0, type_2 = 0;
        for (pii it : cnt)
            (it.se >= 2 ? type_2++ : type_1++);
        
        if (((type_1 + type_2) > 2*k) || ((type_1 + 2*type_2) < 2*k))
            cout << "NO\n";
        else cout << "YES\n";

        cnt.clear();
    }
}