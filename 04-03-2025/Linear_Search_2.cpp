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

int n;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin >> n;
    int *arr = new int[n];
    for (int i=0;i < n;i++ )    cin >> arr[i];
    int x;  cin >> x;

    vector<pii> res;
    for (int i=0;i< n;i++ ){
        if (arr[i] == x){
            res.push_back({i, i + 1});
        }
    }

    cout << ((int)res.size()) << '\n';
    for (pii it : res){
        cout << it.fi << ' ' << it.se <<'\n';
    }
    
}