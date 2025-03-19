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

int n;
int arr[N + 5];
int sorted[N + 5];
vector<int> value;
vector<int> idx[N + 5];
bool used[N + 5];

ll solve(){
    for (int i=0;i<= n;i++ )
        vector<int> ().swap(idx[i]);
        
    memset(used, false, sizeof(used));
    for (int i=1;i<= n;i++ )
        if (arr[i] == sorted[i])
            used[i] = true;
        else idx[sorted[i]].push_back(i);
    
    ll ret = 0;
    for (int i=1;i<= n;i++ ){
        int cur = i;
        int cnt = 0;
        while (!used[cur]){
            used[cur] = true;
            cnt++;
            int _next = idx[arr[cur]].back();
            idx[arr[cur]].pop_back();
            cur = _next;
        }
        ret += (cnt > 0 ? cnt - 1 : 0);
    }

    return ret;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n;
    for (int i=1;i<= n;i++ ){
        cin >> arr[i];
        value.push_back(arr[i]);
    }
    sort(ALL(value));
    UNIQUE(value);
    for (int i=1;i<= n;i++ )
        arr[i] = lower_bound(ALL(value), arr[i]) - value.begin();

    for (int i=1;i<= n;i++ )
        sorted[i] = arr[i];

    ll res = LLONG_MAX;
    sort(sorted + 1, sorted + n + 1);
    res = min(res,solve());
    sort(sorted + 1, sorted + n + 1, greater<int>());
    res = min(res,solve());
    cout << res;
}