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
const int N = 20;

int n;

template <class T>
inline void merge(T arr[], int _left, int mid, int _right){    
    int left_size = mid - _left + 1;           
    int right_size = _right - mid;            

    T *left_arr = new T[left_size];
    for (int i=0;i< left_size;i++ )
        left_arr[i] = arr[_left + i];

    T *right_arr = new T[right_size];
    for (int i=0;i< right_size;i++ )
        right_arr[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = _left;
    while (i < left_size && j < right_size){ 
        if (left_arr[i] <= right_arr[j])
            arr[k++] = left_arr[i++];
        else    arr[k++] = right_arr[j++];
    }

    while (i < left_size)
        arr[k++] = left_arr[i++];

    while (j < right_size)
        arr[k++] = right_arr[j++];
    
    delete[] left_arr;
    delete[] right_arr;
}

template<class T>
void MergeSort(T *arr, int _left, int _right){
    if (_left >= _right)    return;
    int mid = (_left + _right) >> 1;
    MergeSort(arr, _left, mid);
    MergeSort(arr, mid+1, _right);
    merge(arr, _left, mid, _right);
    for (int i=0;i< n;i++ ){
        if (i == _left) cout << "[ ";
        cout << arr[i] << ' ';
        if (i == _right)    cout << "] ";
    }
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
    MergeSort(arr, 0, n - 1);
}