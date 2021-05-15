#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007;
#define INF 1e18
using namespace std;

int main() {
	ll n; cin >> n;
	vector<array<ll, 3>> arr(n);
	for(ll i = 0; i < n; i++){
		ll a, b, p; cin >> a >> b >> p;
		arr[i][0] = a;
		arr[i][1] = b;
		arr[i][2] = p;
	}
	ll ans = 0;
	for(ll i = 0; i < n; i++){
		ll arrive = arr[i][0];
		ll leave = arr[i][1];
		ll money = arr[i][2];
		for(ll j = 0; j < n; j++){
			if(i==j) continue;
			if(arr[j][0] > leave || arr[j][1] < arrive){
				money += arr[j][2];

			}
		}
		ans = max(ans, money);
	}
	cout << ans << endl;
}