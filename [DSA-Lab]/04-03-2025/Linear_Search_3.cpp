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

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    int n;  cin >> n;
    int *arr = new int[n];
    set<int> mex;
    for (int i=0;i<= n;i++ )
        mex.insert(i);
    for (int i=0;i < n;i++ ){
        cin >> arr[i];
        if (mex.find(arr[i]) != mex.end())
            mex.erase(arr[i]);

        cout << *(mex.begin()) << ' ';
    }

}