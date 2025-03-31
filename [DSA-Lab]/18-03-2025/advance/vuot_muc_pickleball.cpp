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
const int A = 200;

int n, d;
int arr[N + 5];
int cnt[A + 5];

int findMedian(int pos){
    for (int i=0;i<= 200;i++ ){
        if (pos > cnt[i])   pos -= cnt[i];
        else    return i;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n >> d;
    for (int i=1;i<= n;i++ )
        cin >> arr[i];
    int res = 0;
    
    for (int i=1;i<= n;i++ ){
        if (i <= d){
            cnt[arr[i]]++;
            continue;
        }
        else{
            if (d % 2 == 1){
                int median = findMedian(d/2 + 1);
                if (arr[i] >= 2*median)
                    res++;
            }
            else{
                int median_l = findMedian(d/2);
                int median_r = findMedian(d/2 + 1);
                if (arr[i] >= (median_l + median_r))
                    res++;
            }
            cnt[arr[i]]++;
            cnt[arr[i - d]]--;
        }
    }
    cout << res;
}