#include <bits/stdc++.h>
#define ll long long
#define MOD 1e9 + 7;
#define INF 1e18
using namespace std;

int main() {
	ll n; cin >> n;
	vector<ll> coins(n+1);
	ll sum = 0;
	for(ll i =1; i <= n; i++){
		cin >> coins[i];
		sum += coins[i];
	}
	vector<ll> dp(sum+1);
	dp[0] = true;
	for(ll i = 1; i <= n; i++){
		for(ll j = sum; j >= coins[i]; j--){
				dp[j] |= dp[j - coins[i]];
		}
	}	
	ll count = 0;
	for(ll i = 1; i <= sum; i++) if(dp[i] == 1) count++;
	cout << count << endl;
	for(ll i = 1; i <= sum; i++) if(dp[i] == 1) cout << i << " "; 
	return 0;
}