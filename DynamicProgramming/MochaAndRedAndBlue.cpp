#include <algorithm>
#include <array>
#include <climits>
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
  string s;
  cin >> s;
  ll lp = 0;
  ll rp;
  for (rp = 0; rp < n; rp++) {
    if (s[rp] != '?') {
      if (lp < rp) {
        char target = s[rp];
        for (ll i = rp - 1; i >= lp; i--) {
          target = (target == 'B' ? 'R' : 'B');
          s[i] = target;
        }
      }
      lp = rp + 1;
    }
  }
  if (lp < n) {
    char target;
    if (lp == 0) {
      target = 'B';
    } else {
      target = s[lp - 1];
    }
    for (ll i = lp; i < n; i++) {
      target = (target == 'B' ? 'R' : 'B');
      s[i] = target;
    }
  }
  cout << s << endl;
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
