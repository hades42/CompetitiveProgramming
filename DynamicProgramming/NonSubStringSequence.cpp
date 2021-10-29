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
  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  for (int i = 0; i < q; i++) {
    ll l, r;
    cin >> l >> r;
    ll first = s[l - 1];
    ll last = s[r - 1];
    bool bad = true;
    for (ll i = 0; i < l - 1; i++) {
      if (s[i] == first)
        bad = false;
    }
    for (ll i = r; i < n; i++) {
      if (s[i] == last)
        bad = false;
    }
    if (bad) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
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
