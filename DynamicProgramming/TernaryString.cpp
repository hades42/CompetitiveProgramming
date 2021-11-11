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
  string s;
  cin >> s;
  vector<pair<ll, ll>> arr;
  ll ans = INF;
  for (ll i = 0; i < s.size(); i++) {
    if (arr.empty() || arr.back().first != s[i]) {
      arr.push_back(make_pair(s[i], 1));
    } else {
      arr.back().second++;
    }
  }
  for (ll i = 1; i < arr.size() - 1; i++) {
    if (arr[i - 1].first != arr[i + 1].first) {
      ans = min(ans, arr[i].second + 2);
    }
  }
  if (ans == INF)
    ans = 0;
  cout << ans << endl;
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
