#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;

int main() {
	ll n, target;
	cin >> n >> target;
	vector<ll> coins(n);
	for(int i = 0; i < n; i++){
		cin >> coins[i];
	}
	vector<ll> construct(target+1);
	construct[0] = 0;
	for(ll i =1 ; i <= target; i++){
		construct[i] = INF;
		for(ll c : coins){
			if(i - c >= 0){
				construct[i] = min(construct[i], construct[i - c] + 1);
			}
		}
	}
	if(construct[target] == INF) cout << -1 << endl;
	else cout << construct[target] << endl;
	return 0;
}