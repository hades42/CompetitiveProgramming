#include <bits/stdc++.h>
#define ll long long
#define MOD 1e9 + 7;
const ll INF  = 1e18;
using namespace std;

int main() {
	ll a, b;
	cin >> a >> b;
	vector<vector<ll>> dp(a+1, vector<ll>(b+1, INF));
	for(ll i = 0; i <= min(a,b); i++){
		dp[i][i] = 0;
	}
	for(ll height = 0; height <= a; height++){
		for(ll width = 0; width <= b; width++){
			for(ll i = 1; i < width; i++){
				dp[height][width] = min(dp[height][width], 1 +dp[height][width - i] + dp[height][i]);
			}
			for(ll i = 1; i < height; i++){
				dp[height][width] = min(dp[height][width], 1 + dp[height - i][width] + dp[i][width]);
			}
		}
	}	
	cout << dp[a][b] << endl;
	return 0;
}