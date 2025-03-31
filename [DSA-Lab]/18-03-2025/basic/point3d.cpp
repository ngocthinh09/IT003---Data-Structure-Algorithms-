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

struct Point3D{
    int x, y, z;
    bool operator < (const Point3D &other)  const{
        if (x == other.x){
            if (y == other.y)
                return (z < other.z);
            return (y > other.y);
        }
        return (x < other.x);
    }
};

int n;
Point3D pt[N + 5];

void quickSort(Point3D arr[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    Point3D pivot = arr[mid];

    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (pivot < arr[j]) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
   if (fopen(problem".inp","r")){
       freopen(problem".inp","r",stdin);
       freopen(problem".out","w",stdout);
   }
    cin >> n;
    for (int i=1;i<= n;i++ )
        cin >> pt[i].x >> pt[i].y >> pt[i].z;
    quickSort(pt, 1, n);
    for (int i=1;i<= n;i++ )
        cout << pt[i].x << ' ' << pt[i].y << ' ' << pt[i].z << '\n';
}