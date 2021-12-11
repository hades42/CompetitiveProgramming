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
  setIO("paintbarn");
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> arr(1005, vector<ll>(1005));
  for (ll i = 0; i < n; i++) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    arr[x1][y1]++;
    arr[x1][y2]--;
    arr[x2][y1]--;
    arr[x2][y2]++;
  }

  for (ll i = 0; i < 1000; i++) {
    for (ll j = 0; j < 1000; j++) {
      if (i > 0) {
        arr[i][j] += arr[i - 1][j];
      }
      if (j > 0) {
        arr[i][j] += arr[i][j - 1];
      }
      if (i > 0 & j > 0) {
        arr[i][j] -= arr[i - 1][j - 1];
      }
    }
  }
  // for (ll i = 0; i <= 10; i++) {
  // for (ll j = 0; j <= 10; j++) {
  // cout << arr[i][j] << " ";
  //}
  // cout << endl;
  //}
  ll res = 0;
  for (ll i = 0; i < 1000; i++) {
    for (ll j = 0; j < 1000; j++) {
      if (arr[i][j] == k) {
        res++;
      }
    }
  }
  cout << res << endl;
}
