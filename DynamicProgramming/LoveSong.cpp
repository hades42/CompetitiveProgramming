#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<ll> cnt(27, 0);
  vector<vector<ll>> prefix(200005, vector<ll>(27));
  for (ll i = 0; i < n; i++) {
    ++cnt[s[i] - 'a'];
    for (ll j = 0; j < 27; j++) {
      prefix[i][j] = cnt[j];
    }
  }
  for (int i = 0; i < q; i++) {
    ll l, r;
    cin >> l >> r;
    --l;
    --r;
    ll res = 0;
    for (int j = 0; j < 27; j++) {
      ll c = prefix[r][j];
      if (l > 0)
        c -= prefix[l - 1][j];
      res += c * (j + 1);
    }
    cout << res << endl;
  }
}
