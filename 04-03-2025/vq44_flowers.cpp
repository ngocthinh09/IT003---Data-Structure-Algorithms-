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

int n,k;
int a[N + 5];
bool isUsed[N + 5];
map<int,bool> check;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin >> n >> k;
    for (int i=1;i<= n;i++ )
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i=1;i<= n & k > 0;i++ ){
        if (check[a[i]] == false){
            cout << a[i] << ' ';
            check[a[i]] = true;
            isUsed[i] = true;
            k--;
        }
    }
    
    for (int i=1;i<= n && k > 0;i++ ){
        if (!isUsed[i]){
            cout << a[i] << ' ';
            isUsed[i] = true;
            k--;
        }
    }
    
}