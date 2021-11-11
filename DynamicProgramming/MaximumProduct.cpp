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

bool sortabs(ll x, ll y) { return abs(x) > abs(y); }
void solve() {
  ll n;
  cin >> n;
  vector<ll> arr(n);
  ll mx = -INF;
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
  }
  sort(arr.begin(), arr.end(), sortabs);
  ll ans = arr[0] * arr[1] * arr[2] * arr[3] * arr[4];
  if (mx < 0) {
    cout << arr[n - 1] * arr[n - 2] * arr[n - 3] * arr[n - 4] * arr[n - 5]
         << endl;
  } else {
    for (ll i = 5; i < n; i++) {
      for (ll j = 0; j < 5; j++) {
        ll temp = arr[i];
        for (ll z = 0; z < 5; z++) {
          if (j != z)
            temp *= arr[z];
        }
        ans = max(ans, temp);
      }
    }
    cout << ans << endl;
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
