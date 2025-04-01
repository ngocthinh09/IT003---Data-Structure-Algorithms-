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
const int N = 5e4;

struct Item{
    string str;

    Item (string _str = ""){
        str = _str;
    }
};

bool operator < (const Item &lhs, const Item &rhs){
    string l = lhs.str;
    string r = rhs.str;
    if (l.length() != r.length())
        return l.length() < r.length();
    else{
        for (int i=0;i < (int)l.length();i++ ){
            if (l[i] != r[i])
                return (l[i] < r[i]);
            }
    }
    return false;
}

struct Package{
    int cnt;
    Item it;

    Package (int _cnt = 0, Item _it = Item()){
        cnt = _cnt, it = _it;
    }

    bool operator < (const Package &other)  const{
        if (cnt == other.cnt)
            return it < other.it;
        else
            return cnt > other.cnt;
    }
};

template<class T>
void QuickSort(T *arr, int _left, int _right){
    if (_left >= _right) return;
    int mid = (_left + _right) >> 1;
    T pivot = arr[mid];

    int i = _left, j = _right;
    while (i < j){
        while (arr[i] < pivot)  i++;
        while (pivot < arr[j])  j--;

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

Item items[N + 5];
Package pack[N + 5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    int n;  cin >> n;
    for (int i=0;i< n;i++ )
        cin >> items[i].str;
        
    QuickSort(items, 0, n-1);
    
    
    int numPack = 0;
    for (int i=0;i< n;i++ ){
        string last = items[i].str;
        int j = i;
        while (j + 1 < n && items[j + 1].str == last)
            j++;
        pack[numPack++] = Package(j - i + 1, Item(last));
        i = j;
    }

    QuickSort(pack, 0, numPack-1);
    for (int i=0;i < numPack;i++ )
        cout << pack[i].it.str << ' ' << pack[i].cnt << '\n';
}