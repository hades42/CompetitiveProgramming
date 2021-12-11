#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <numeric>
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
  ll n, q;
  cin >> n >> q;
  vector<string> arr(n);
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<vector<ll>> forest(n + 1, vector<ll>(n + 1));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      if (arr[i][j] == '*') {
        forest[i + 1][j + 1] =
            forest[i][j + 1] + forest[i + 1][j] + 1 - forest[i][j];
      } else {
        forest[i + 1][j + 1] =
            forest[i][j + 1] + forest[i + 1][j] - forest[i][j];
      }
    }
  }

  for (ll i = 0; i < q; i++) {
    ll y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    ll ans = forest[y2][x2] - forest[y2][x1 - 1] - forest[y1 - 1][x2] +
             forest[y1 - 1][x1 - 1];
    cout << ans << endl;
  }
}
