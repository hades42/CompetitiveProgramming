#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;

const ll MOD = 1e9+7;
const ll n = 1e6+1;
vector<array<ll,2>> dp(n+1);

void precompute(){
	dp[1][0] = dp[1][1] = 1;
	for(ll i = 2; i < n; i++){
		dp[i][0] = (dp[i-1][1] + 4*dp[i-1][0]) % MOD;
		dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1]) % MOD;
	}
}
int main() {
	ll t; cin >> t;
	precompute();
	while(t--){
		ll num; cin >> num;
		ll ans = (dp[num][0] + dp[num][1]) % MOD;
		cout << ans << endl;
	}
}