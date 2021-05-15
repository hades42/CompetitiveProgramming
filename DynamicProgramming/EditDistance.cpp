#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
	string in1, in2;
	cin >> in1 >> in2;
	ll len1 = in1.size();
	ll len2 = in2.size();
	vector<vector<ll>> dp(len1 + 1, vector<ll>(len2 + 1, INF));
	dp[0][0] = 0;
	for(int i = 0; i <= len1; i++){
		for(int j = 0; j<= len2; j++){
			if(i -1 >= 0 && j-1 >= 0){
				bool same = in1[i-1] == in2[j-1]; 
				dp[i][j] = min(dp[i][j], dp[i-1][j-1] + !same); 
			}
			if(i-1 >= 0){
				dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
			}
			if(j-1 >= 0){
				dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
			}
		}
	}
	cout << dp.back().back() << endl;	
	return 0;
}