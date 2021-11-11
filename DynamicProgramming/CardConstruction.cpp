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
  ll num;
  cin >> num;
  vector<ll> dp;
  dp.push_back(0);
  dp.push_back(2);
  ll start = 1;
  for (ll i = 2;; i++) {
    dp.push_back(i * 2 + i - 1 + dp[i - 1]);
    if (dp[i] > num) {
      start = i;
      break;
    }
  }
  // print(dp);
  // cout << start << endl;
  ll count = 0;
  for (ll i = start; i >= 1; i--) {
    while (num >= dp[i]) {
      count++;
      num -= dp[i];
    }
  }
  cout << count << endl;
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
