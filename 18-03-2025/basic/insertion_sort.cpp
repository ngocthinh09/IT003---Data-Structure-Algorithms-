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
const int N = 200;

int n;

template<class T>
void print(T *arr, int n){
    for (int i=0;i< n;i++ )
        cout << arr[i] << ' ';
    cout << '\n';
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    cin >> n;
    int *arr = new int[n];
    for (int i=0;i< n;i++ ) cin >> arr[i];
    
    for (int i=1;i< n;i++ ){
        int val = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > val){
            arr[j] = arr[j - 1];
            print(arr, n);
            j--;
        }
        arr[j] = val;
        print(arr, n);
    }
}