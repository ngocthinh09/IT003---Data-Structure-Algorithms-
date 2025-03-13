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


pii binary_search(int arr[], int n, int x){
    int pos = 0, cnt = 0;
    int l = 0, r = n - 1;
    while (l <= r){
        int mid = (l + r) >> 1;
        cnt++;
        if (arr[mid] < x)
            l = mid + 1;
        else if (arr[mid] > x)
            r = mid - 1;
        else
            return pii(mid, cnt);
    }
    return {-1, -1};
}

int n, x;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin >> n;
    int *arr = new int[n];
    for (int i=0;i < n;i++ )    cin >> arr[i];
    cin >> x;
    pii pos = binary_search(arr, n, x);
    cout << pos.fi <<'\n';
    if (pos.fi != -1)
        cout << pos.se;
}