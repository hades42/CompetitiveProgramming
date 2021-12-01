#include <algorithm>
#include <array>
#include <cstdio>
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

void setIO(string s) { // the argument is the filename without the extension
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  setIO("triangles");
  ll n;
  cin >> n;
  vector<pr> arr(n);
  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    arr[i] = make_pair(x, y);
  }
  ll res = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      if (i == j)
        continue;
      for (ll z = 0; z < n; z++) {
        if (z == i || z == j)
          continue;

        ll diffx1 = abs(arr[i].first - arr[j].first);
        ll diffy1 = abs(arr[i].second - arr[j].second);

        ll diffx2 = abs(arr[i].first - arr[z].first);
        ll diffy2 = abs(arr[i].second - arr[z].second);

        if (diffx1 == 0 && diffy2 == 0) {
          res = max(res, diffx2 * diffy1);
        }
        if (diffx2 == 0 && diffy1 == 0) {
          res = max(res, diffx1 * diffy2);
        }
      }
    }
  }
  cout << res << endl;
}
