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
const int N = 5e5;

template<class T>
void QuickSort(T *arr, int _left, int _right){
    if (_left >= _right)    return;
    int mid = (_left + _right) >> 1;
    T pivot = arr[mid];

    int i = _left, j = _right;
    while (i < j){
        while (arr[i] < pivot) i++;
        while (pivot < arr[j]) j--;
        
        if (i <= j){
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }

    if (_left < j)  QuickSort(arr, _left, j);
    if (i < _right) QuickSort(arr, i, _right);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    int n, q;  cin >> n >> q;
    int *arr = new int[n];
    int *copy = new int[n];
    for (int i=0;i< n;i++ ){
        cin >> arr[i];
        copy[i] = arr[i];
    }

    QuickSort(copy, 0, n-1);
    vector<int> value;
    for (int i=0;i< n;i++ )
        value.push_back(copy[i]);
    UNIQUE(value);
    
    for (int i=0;i< n;i++ )
        arr[i] = lower_bound(ALL(value), arr[i]) - value.begin();

    int MAX_INT = 1e9, MIN_INT = -1e9;
    int *maxPos = new int[n];
    for (int i=0;i< n;i++ )
        maxPos[i] = MIN_INT;

    int *minPos = new int[n];
    for (int i=0;i< n;i++ )
        minPos[i] = MAX_INT;
    
    for (int i=0;i< n;i++){
        minPos[arr[i]] = min(minPos[arr[i]], i);
        maxPos[arr[i]] = max(maxPos[arr[i]], i);
    }

    while (q-- ){
        string s;   cin >> s;
        int type, p;    cin >> type >> p;
        int idx = lower_bound(ALL(value), p) - value.begin();
        if (value[idx] != p)
            cout << -1 << '\n';
        else{
            if (type == 1)
                cout << minPos[idx] + 1 << '\n';
            else
                cout << maxPos[idx] + 1 << '\n';
        }
    }
}