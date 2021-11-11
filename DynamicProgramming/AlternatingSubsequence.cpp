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

ll check(ll x) {
  if (x > 0)
    return 1;
  else
    return -1;
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    ll curr = arr[i];
    ll j = i;
    while (j < n && check(arr[i]) == check(arr[j])) {
      curr = max(curr, arr[j]);
      j++;
    }
    sum += curr;
    i = j - 1;
  }
  cout << sum << endl;
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
