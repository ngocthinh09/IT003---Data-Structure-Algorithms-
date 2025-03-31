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

int k;
string str;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    // freopen(problem".inp","r",stdin);
    // freopen(problem".out","w",stdout);
    cin >> k;
    cin.ignore();
    getline(cin, str);


    for (int i=0;i< (int)str.length();i++ ){
        if ('A' <= str[i] && str[i] <= 'Z'){
            str[i] = char((((str[i] - 'A') + k) % 26) + 'A');
        }
        cout << str[i];
    }
}