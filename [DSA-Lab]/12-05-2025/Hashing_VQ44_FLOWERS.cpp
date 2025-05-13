#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;

    for (int i=0;i< n;i++ )
        Hash[A[i]]++;
    vector<int> res;
    if (Hash.size() >= K){
        for (auto it : Hash){
            res.push_back(it.first);
            if (res.size() == k)    break;
        }
        return res;
    }
    else{
        for (auto it : Hash){
            res.push_back(it.first);
            Hash[it.first]--;
        }
        for (auto it : Hash)
            while (Hash[it.first] > 0 && res.size() < K){
                res.push_back(it.first);
                Hash[it.first]--;
            }
        return res;
    }
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> k;
	
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> ans = get_ans(a,k);
	
	for (const int& x: ans) cout << x << ' ';
	return 0;
}
