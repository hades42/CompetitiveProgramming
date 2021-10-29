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
  ll r;
  cin >> r;
  vector<ll> red(r);
  for (ll i = 0; i < r; i++) {
    cin >> red[i];
  }
  ll b;
  cin >> b;
  vector<ll> blue(b);
  for (ll i = 0; i < b; i++) {
    cin >> blue[i];
  }
  ll ans = 0;

  ll b2 = 0;
  for (ll i = 0; i < b; i++) {
    b2 += blue[i];
    ans = max(ans, b2);
  }
  ll curr = 0;
  for (ll i = 0; i < r; i++) {
    curr += red[i];
    ans = max(ans, curr);

    b2 = 0;
    for (ll j = 0; j < b; j++) {
      b2 += blue[j];
      ans = max(ans, curr + b2);
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
