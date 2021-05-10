#include <bits/stdc++.h>
#define ll long long
#define MOD 1e9 + 7;
#define INF 1e18
using namespace std;

int main() {
	ll n, target; cin >> n >> target;
	vector<ll> money(n + 1);
	vector<ll> pages(n + 1);
	for (ll i = 1; i <= n; i++) cin >> money[i];
	for (ll i = 1; i <= n; i++) cin >> pages[i];

	vector<ll> dp(target + 1);
	// ll mx = 0;
	for (ll m = 1; m <= n; m++) {
		for (int x = target; x >= money[m]; x--) {
			if(x - money[m] >= 0){
				dp[x] = max(dp[x], dp[ x - money[m]] + pages[m]);
			}
		}
	}
	cout << dp[target] << endl;
	return 0;
}