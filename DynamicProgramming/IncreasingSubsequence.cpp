#include <bits/stdc++.h>
#define ll long long
#define MOD 1e9 + 7;
#define INF 1e18
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> dp;
	vector<int>::iterator it;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		it = lower_bound(dp.begin(), dp.end(), x);
		if (it == dp.end()) {
			dp.push_back(x);
		} else {
			*it = x;
		}
	}
	cout << dp.size() << endl;
	return 0;
}