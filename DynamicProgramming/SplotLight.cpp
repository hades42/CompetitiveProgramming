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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> arr(n, vector<ll>(m));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  ll res = 0;

  // Check for the left
  for (ll i = 0; i < n; i++) {
    ll f = false;
    for (ll j = 0; j < m; j++) {
      ll curr = arr[i][j];
      if (curr == 1) {
        f = true;
      } else {
        if (f) {
          res++;
        }
      }
    }
  }

  // Check for the right
  for (ll i = 0; i < n; i++) {
    ll f = false;
    for (ll j = m - 1; j >= 0; j--) {
      ll curr = arr[i][j];
      if (curr == 1) {
        f = true;
      } else {
        if (f) {
          res++;
        }
      }
    }
  }

  // Check for top -> bottom
  for (ll j = 0; j < m; j++) {
    ll f = false;
    for (ll i = 0; i < n; i++) {
      ll curr = arr[i][j];
      if (curr == 1) {
        f = true;
      } else {
        if (f) {
          res++;
        }
      }
    }
  }

  // Check for bottom -> top
  for (ll j = 0; j < m; j++) {
    ll f = false;
    for (ll i = n - 1; i >= 0; i--) {
      ll curr = arr[i][j];
      if (curr == 1) {
        f = true;
      } else {
        if (f) {
          res++;
        }
      }
    }
  }
  cout << res << endl;
}
