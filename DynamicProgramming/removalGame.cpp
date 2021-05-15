#include <bits/stdc++.h>
#define ll long long
#define MOD 1e9 + 7;
#define INF 1e18
using namespace std;

int main() {
	ll n; cin >> n;
	vector<ll> point(n) ;
	ll sum = 0;
	for(ll i = 0; i < n; i++){
		cin >> point[i];
		sum += point[i];
	}
	vector<vector<ll>> dp(n, vector<ll>(n));
	for(ll l = n -1; l >= 0; l--){
		for(ll r = l; r < n; r++){
			if(l == r){
				dp[l][r] = point[l];
			}
			else{
				dp[l][r] = max(point[l] - dp[l+1][r], point[r] - dp[l][r-1]);
			}
		}
	}
	cout << (dp[0][n-1] + sum)/2 << endl;
	return 0;
}