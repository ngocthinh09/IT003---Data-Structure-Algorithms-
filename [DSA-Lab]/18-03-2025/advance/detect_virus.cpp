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

void prefix_function(const string &str, int *pi){
    for (int i=1;i< str.length();i++ ){
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j])
            j = pi[j - 1];
        if (str[i] == str[j])
            j++;
        pi[i] = j;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);	cout.tie(NULL);
    if (fopen(problem".inp", "r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    string str, pattern;
    cin >> str >> pattern;
    int n = pattern.length(), m = str.length();
    string T = pattern + "#" + str;
    int *pi = new int[n + m + 1];
    for (int i=0;i< n + m + 1;i++ )
        pi[i] = 0;
    prefix_function(T, pi);
    
    vector<int> value;
    for (int i=0;i< T.length();i++ ){
        if (pi[i] == n){
            value.push_back(i - (n + 1));
        }
    }
    
    if ((int)value.size()){
        cout << "YES\n";
        for (int i : value)
            cout << i - n + 2 << ' ';
    }
    else cout << "NO";
}