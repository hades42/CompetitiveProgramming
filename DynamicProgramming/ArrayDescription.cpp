#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
int main() {
	ll n, m; cin >> n >> m;
	vector<ll> arr(n);
	for(ll i = 0; i< n; i++) cin >> arr[i];	
	vector<vector<ll>> dp(n, vector<ll>(m+1));
	
	if(arr[0] == 0){
		for(ll i = 1; i <= m; i++) dp[0][i] = 1;
	} else dp[0][arr[0]] = 1;

	for(ll i = 1; i < n; i++){
		if(arr[i] == 0){
			for(ll j = 1; j <= m; j++){
				dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
				if(j > 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
				if(j < m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
			}
		} else{
			dp[i][arr[i]] += dp[i-1][arr[i]];
			if(arr[i] > 1) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i] -1]) % MOD;
			if(arr[i] < m) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i-1][arr[i] +1]) % MOD;
		}
	}
	ll ans = 0;
	for(ll i = 1; i <= m; i++) ans = (ans + dp[n-1][i]) % MOD;	
	cout << ans << endl;
}