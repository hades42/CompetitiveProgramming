#include <bits/stdc++.h>
#define ll long long
const ll MOD = 1e9 + 7;
#define INF 1e18
using namespace std;
 
vector<int> coins = {1, 2, 3, 4, 5, 6};
int main() {
	int n; cin >> n;
	vector<int> ways(n+1);
	ways[0] = ways[1] = 1;
	for(int i = 2; i<= n; i++){
		for(int j = 0; j < coins.size(); j++){
			if(i - coins[j] >= 0){
				ways[i] = (ways[i] + ways[i-coins[j]]) % MOD;
			}
		} 
	}
	cout << ways[n] << endl;
	return 0;
}