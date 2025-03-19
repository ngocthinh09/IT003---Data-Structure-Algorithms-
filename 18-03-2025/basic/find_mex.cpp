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

template<class T>
void QuickSort(T arr[], int _left,int _right){
    if (_left >= _right)    return;

    int mid = (_left + _right) >> 1;
    T pivot = arr[mid];                

    int i = _left, j = _right;
    while (i < j){                      
        while (arr[i] < pivot)  i++;    
        while (arr[j] > pivot)  j--;

        if (i <= j){
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }

    if (_left < j)
        QuickSort(arr, _left, j);
    if (i < _right)
        QuickSort(arr, i, _right);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    if (fopen(problem".inp","r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    int n;  cin >> n;
    ll *arr = new ll[n];
    for (int i=0;i< n;i++ )
        cin >> arr[i];

    QuickSort(arr, 0, n - 1);
    for (int i=0;i<= n;i++ )
        if (!binary_search(arr, arr + n, i))
            return void(cout << i), 0;
}