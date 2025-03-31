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

int cnt[10];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    if (fopen(problem".inp","r")){
        freopen(problem".inp","r",stdin);
        freopen(problem".out","w",stdout);
    }
    string str; cin >> str;
    int n = str.length();
    int mod = 0;
    for (int i=0;i< n;i++ ){
        int id = str[i] - '0';
        cnt[id]++;
        mod += id;
    }
    int mod_1[] = {1, 4, 7};
    int mod_2[] = {2, 5, 8};
    mod %= 3;
    
    if (mod == 1){
        for (int d : mod_1)
            while (mod > 0 && cnt[d] > 0){
                cnt[d]--;
                mod--;
            }
    }
    else if (mod == 2){
        for (int d : mod_2){
            while (mod > 0 && cnt[d] > 0){
                cnt[d]--;
                mod -= 2;
            }
        }
    }

    if (mod == 2){
        for (int d : mod_1){
           while (mod > 0 && cnt[d] > 0){
                cnt[d]--;
                mod = (mod - 1 + 3) % 3;
           }
        }
    }
    else if (mod == 1){
        for (int d : mod_2){
            while (mod > 0 && cnt[d] > 0){
                cnt[d]--;
                mod = (mod - 2 + 3) % 3;
            }
         }
    }

    for (int i=9;i>= 0;i--)
        while (cnt[i] > 0){
            cout << i;
            cnt[i]--;
        }
}