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
deque<int> dq;
int cnt[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n >> m;
    while (!dq.empty())     dq.pop_back();
    for (int i=1;i<= n;i++ ){
        dq.push_back(i);
        cnt[i] = 1;
    }

    while (m-- ){
        int p;  cin >> p;
        dq.push_front(p);
        cnt[p]++;
        while (!dq.empty() && cnt[dq.back()] > 1){
            cnt[dq.back()] -= 1;
            dq.pop_back();
        }
        cout << dq.back() << ' ';
    }
}