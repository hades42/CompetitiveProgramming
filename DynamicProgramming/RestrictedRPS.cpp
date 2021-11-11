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
  ll a, b, c;
  cin >> a >> b >> c;
  string s;
  cin >> s;
  string res = "";
  vector<ll> arr(26);

  for (ll i = 0; i < n; i++) {
    arr[s[i] - 'A']++;
  }

  ll win =
      min(a, arr['S' - 'A']) + min(b, arr['R' - 'A']) + min(c, arr['P' - 'A']);
  if (2 * win < n) {
    cout << "NO" << endl;
    return;
  }
  for (ll i = 0; i < n; i++) {
    if (s[i] == 'R' && b) {
      res += 'P';
      b--;
    } else if (s[i] == 'P' && c) {
      res += 'S';
      c--;
    } else if (s[i] == 'S' && a) {
      res += 'R';
      a--;
    } else {
      res += '_';
    }
  }

  for (ll i = 0; i < n; i++) {
    if (res[i] != '_') {
      continue;
    }

    if (a) {
      res[i] = 'R';
      a--;
    } else if (b) {
      res[i] = 'P';
      b--;
    } else {
      res[i] = 'S';
      c--;
    }
  }
  cout << "YES" << endl;
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
