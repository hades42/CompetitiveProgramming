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
  vector<ll> arr(3);
  for (ll i = 0; i < 3; i++) {
    cin >> arr[i];
  }
  vector<ll> res(3);
  for (ll i = 0; i < 3; i++) {
    for (ll j = 0; j < 3; j++) {
      if (i == j)
        continue;
      if (arr[j] >= arr[i]) {
        res[i] = max(res[i], arr[j] - arr[i] + 1);
      }
    }
  }
  print(res);
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
