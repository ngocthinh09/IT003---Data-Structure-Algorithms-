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

string a, b;
int len_a, len_b;

bool check(int pos){
    int i = pos, j = 0;
    while (i < len_a && j < len_b){
        if (a[i] != b[j])
            break;
        i++ , j++;
    }
    return ((i < len_a) ? false : true);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    freopen(problem".inp","r",stdin);
    freopen(problem".out","w",stdout);
    cin >> a >> b;
    len_a = (int)a.length();
    len_b = (int)b.length();

    string str = "";
    for (int i=0;i< len_a;i++ ){
        if (check(i))
            break;
        str += a[i];
    }
    str += b;
    cout << (int)str.length() <<'\n';
    cout << str;
}