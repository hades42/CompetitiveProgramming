#include <algorithm>
#include <array>
#include <cstdio>
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

void setIO(string s) { // the argument is the filename without the extension
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
  ll n;
  cin >> n;
  set<pair<ll, ll>> s;
  for (ll i = 0; i < n; i++) {
    ll num;
    cin >> num;
    if (num == 0)
      continue;
    s.insert({-num, i + 1});
  }
  vector<pair<ll, ll>> res;
  while (s.size() > 1) {
    pair<ll, ll> fi = *s.begin();
    s.erase(s.begin());
    pair<ll, ll> se = *s.begin();
    s.erase(s.begin());

    fi.first++;
    se.first++;
    res.push_back({fi.second, se.second});
    if (fi.first < 0) {
      s.insert({fi.first, fi.second});
    }
    if (se.first < 0) {
      s.insert({se.first, se.second});
    }
  }
  cout << res.size() << endl;
  for (ll i = 0; i < res.size(); i++) {
    cout << res[i].first << " " << res[i].second << endl;
  }
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
