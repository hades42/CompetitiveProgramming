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
  string a, b;
  cin >> a >> b;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll top = a[i];
    ll bottom = b[i];
    if (top != bottom) {
      ans += 2;
      continue;
    } else {
      if (top == '0') {
        ans += 1;
        ll next = i + 1;
        if (next < n) {
          if (a[next] == b[next] && a[next] == '1') {
            ans += 1;
            i++;
          }
        }
      }

      if (top == '1') {
        ll next = i + 1;
        if (next < n) {
          if (a[next] == b[next] && a[next] == '0') {
            ans += 2;
            i++;
          }
        }
      }
    }
  }
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
