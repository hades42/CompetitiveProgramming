#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2 * 100 * 1000 + 13;
const int L = 26;

vector<int> balance[L];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < L; i++)
			balance[i].clear();
		for (int i = 1; i <= n; i++)
		{
			string s;
			cin >> s;
			int initBalance = -(int)s.length();
			for (int j = 0; j < L; j++)
				balance[j].push_back(initBalance);
			for (auto c : s)
				balance[c - 'a'].back() += 2;
		}
		int bestCount = 0;
		int bestLetter = 0;
		for (int i = 0; i < L; i++){
			for(auto num : balance[i]) cout << num << " ";
			cout << endl;
		}
		for (int i = 0; i < L; i++)
		{
			auto& b = balance[i];
			sort(b.begin(), b.end());
			reverse(b.begin(), b.end());
			if (b[0] <= 0) continue;
			int sumBalance = b[0];
			int j = 1;
			for (; j < n && sumBalance > 0; j++)
				sumBalance += b[j];
			if (sumBalance <= 0) j--;
			if (j > bestCount)
			{
				bestCount = j;
				bestLetter = i;
			}
		}

		cout << bestCount << endl;
	}
	return 0;
}