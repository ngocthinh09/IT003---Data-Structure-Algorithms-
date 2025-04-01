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

int n, m;
bool check[N + 5];
int arr[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n >> m;
    for (int i=1;i<= m;i++ )    cin >> arr[i];

    for (int i=m;i>= 1;i-- ){
        int p = arr[i];
        if (!check[p]){
            cout << p << ' ';
            check[p] = true;
        }
    }

    for (int i=1;i<= n;i++ )
        if (!check[i])
            cout << i << ' ';
}