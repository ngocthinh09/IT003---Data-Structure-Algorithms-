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
const int N = 300;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    // freopen(problem".inp","r",stdin);
    // freopen(problem".out","w",stdout);
    string str;
    cin >> str;
    int n = (int)str.length();
    for (int d=1;d<= n;d++ ){
        if ((n % d) != 0)   continue;
        reverse(str.begin(), str.begin() + d); 
    }
    cout << str;
}