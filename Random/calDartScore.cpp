#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#define ll long long
using namespace std;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;
const ll INF = 1e18;

template <typename T> void print(const T &t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, " "));
  cout << endl;
}

template <typename T> void print2d(const T &t) {
  std::for_each(t.cbegin(), t.cend(), print<typename T::value_type>);
  cout << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n;
  cin >> n;
  ll target;
  cin >> target;
  vector<ll> input(n);
  for (ll i = 0; i < n; i++) {
    cin >> input[i];
  }
  vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= target; j++) {
      if (input[i - 1] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - input[i - 1]];
      }
    }
  }
  if (dp[n][target]) {
    cout << "Found a subset with sum " << target << endl;
  } else {
    cout << "Cant find any subset" << endl;
    return 0;
  }
  ll backtrack = target;
  vector<ll> result;
  while (backtrack != 0) {
    for (ll i = 0; i < n; i++) {
      if (backtrack - input[i] > 0) {
        if (dp[n][backtrack - input[i]]) {
          result.push_back(input[i]);
          backtrack -= input[i];
          break;
        }
      }
    }
  }
  print(result);
}
