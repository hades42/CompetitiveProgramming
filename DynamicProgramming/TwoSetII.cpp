#include <bits/stdc++.h>
#define ll long long
const ll MOD = 1e9 + 7;
#define INF 1e18
using namespace std;
 
int main() {
	ll n; cin >> n;
	ll sum = n*(n+1)/2;
	if(sum % 2 != 0){
		cout << 0 << endl;
		return 0;
	}
	ll target = sum /2;
	vector<ll> dp(target+1);
	dp[0] = 1;
	for(ll i = 1; i < n; i++){
		for(ll j = target; j >= i; j--){
			if(j - i >= 0){
				dp[j] = (dp[j] + dp[j-i]) % MOD;
			}
		}
	}
	cout << dp[target] << endl;
	return 0;
}