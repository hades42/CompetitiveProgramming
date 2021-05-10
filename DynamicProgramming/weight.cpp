#include <bits/stdc++.h>
#define ll long long
#define MOD 1e9 + 7;
#define INF 1e18
using namespace std;

int main() {
	int n, target; cin >> n >> target;
	vector<int> weight(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> weight[i];
	}

	vector<vector<int>> dp(n+1, vector<int>(target+1));
	dp[0][0] = true;
	for(int k = 1; k <= n; k++){
		for(int i = 0; i <= target; i++){
			if(i - weight[k] >= 0){
				dp[k][i] |= dp[k-1][i-weight[k]];
			}
			dp[k][i] |= dp[k-1][i];
		}
	}	
}