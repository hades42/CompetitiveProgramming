#include <bits/stdc++.h>
#define ll long long
const ll MOD = 1e9 + 7;
#define INF 1e18
using namespace std;

int main() {
	int n, target; cin >> n >> target;
	vector<int> arr(target + 1);
	vector<int> coins(n);	
	for(int i = 0; i < n; i++) cin >> coins[i];
	arr[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= target; j++){
			if(j - coins[i] >= 0){
				arr[j] = (arr[j] + arr[j-coins[i]]) % MOD;
			}
		}
	}
	cout << arr[target] << endl;
}