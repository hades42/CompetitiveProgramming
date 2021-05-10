#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9 + 7;
#define INF 1e18
using namespace std;

int main() {
	int n; cin >> n;
	char arr[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int dp[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 0;
		}
	}
	if(arr[0][0] != '*') dp[0][0] = 1; 
	else{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != '*') {
				if (i - 1 >= 0) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
				}
				if (j - 1 >= 0) {
					dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
				}
			}
		}
	}
	cout << dp[n-1][n-1] << endl;
	return 0;
}