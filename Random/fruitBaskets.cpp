#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
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

  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll ans = 0;
  for (ll mask = 0; mask < (1 << n); mask++) {
    ll sum = 0;
    ll count = 0;
    for (ll i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        sum += arr[i];
        count++;
      }
    }
    if (sum >= 200 && count > 1) {
      ans += sum;
    }
  }
  cout << ans << endl;
}
