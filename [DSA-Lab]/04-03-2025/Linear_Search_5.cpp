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
int arr[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int numTest;    cin >> numTest;
    while (numTest-- ){
        cin >> n;
        for (int i=1;i<= n;i++ )    cin >> arr[i];
        
        sort (arr + 1, arr + n + 1);
        if (n <= 3)
            cout << arr[n] - arr[1] << '\n';
        else
            cout << (arr[n] + arr[n - 1] - arr[1] - arr[2]) <<'\n';
    }
}