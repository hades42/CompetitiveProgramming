#include <bits/stdc++.h>
#define ll long long
#define MOD 1e9 + 7;
#define INF 1e18
using namespace std;

int main() {
	ll n; cin >> n;
	vector<ll> dp(n+1);
	dp[0] = 0;
	for(ll i = 1; i <= n; i++){
		dp[i] = INF;
		for(ll num = i; num > 0; num/=10){
			ll digit = num % 10;
			if(num - digit >= 0){
				dp[i] = min(dp[i], dp[i - digit] + 1);
			}
		}
	}
	cout << dp[n] << endl;
}