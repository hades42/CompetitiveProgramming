#include <bits/stdc++.h>

using namespace std;

using ll = long long;

//constant initialization
const ll MOD=998244353;
const ll maxn=1e6+10;
const ll INF=1e18;
 
//variables used for the current problem
int n,k,cnt[maxn]; 
vector<vector<int>> a; 
ll ans;

ll fastpow(ll x, ll y){
	ll res = 1;
	while (y>0){
		if (y&1) res = (res*x)%MOD;
		y>>=1;
		x = (x*x)%MOD;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	a.resize(n);
	for (int i=0;i<n;++i){
		cin >> k;
		a[i].resize(k);
		for (int &j : a[i]) {
			cin >> j; ++cnt[j];
		}
	}
	const ll invN = fastpow(n,MOD-2);
	for (int i=0;i<n;++i){
		const ll inv_ai=fastpow(a[i].size(),MOD-2);
		for (const int &j : a[i]){
			ans = (ans +((invN*inv_ai)%MOD)*(invN*cnt[j]%MOD))%MOD;
		}
	}
	cout << ans;
	return 0;
}
