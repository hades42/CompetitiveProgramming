#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
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
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> arr(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  vector<ll> dp(n + 1);
  ll res = 0;
  for (ll i = n; i >= 1; i--) {
    dp[i] = arr[i];
    if (i + dp[i] <= n) {
      dp[i] += dp[i + dp[i]];
    }
    res = max(res, dp[i]);
  }
  cout << res << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
