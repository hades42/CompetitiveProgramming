#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
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
  ll n, q, k;
  cin >> n >> q >> k;
  vector<ll> arr(n);
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  while (q--) {
    ll l, r;
    cin >> l >> r;
    l--;
    r--;
    cout << (arr[l] - 1) + (k - arr[r]) +
                2 * ((arr[r] - arr[l] + 1) - (r - l + 1))
         << endl;
  }
}
