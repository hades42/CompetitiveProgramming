#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
const ll MOD = 1e9 + 7;
using namespace std;

int main() {
	ll n, target; cin >> n >> target;
	vector<ll> coins(n);
	for(ll i = 0; i < n; i++){
		cin >> coins[i];
	}
	vector<ll> ans(target+1);
	ans[0] = 1;
	for(ll i = 1; i<= target; i++){
		for(ll coin : coins){
			if(i - coin >= 0){
				ans[i] = (ans[i] + ans[i-coin]) % MOD;
			}
		}
	}
	cout << ans[target] << endl;
	return 0;
}