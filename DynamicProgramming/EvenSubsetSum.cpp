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
  vector<ll> arr(n);
  ll odd = 0;
  ll even = 0;
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] % 2 == 0)
      even++;
    if (arr[i] % 2 != 0)
      odd++;
  }
  if (odd == 0) {
    cout << 1 << endl;
    cout << 1 << endl;
    return;
  }
  if (even == 0 && odd < 2) {
    cout << -1 << endl;
    return;
  }
  if (even == 0 && odd > 1) {
    cout << 2 << endl;
    cout << 1 << " " << 2 << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      cout << 1 << endl;
      cout << i + 1 << endl;
      return;
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
