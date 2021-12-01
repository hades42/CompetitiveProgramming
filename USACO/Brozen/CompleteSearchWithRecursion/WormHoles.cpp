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
vector<ll> X(13);
vector<ll> Y(13);
vector<ll> rightSide(13);
vector<ll> pairing(13);
ll n;
ll res = 0;

ll isCycle() {
  for (ll i = 1; i <= n; i++) {
    ll start = i;
    for (ll count = 0; count < n; count++) {
      start = pairing[start];
      start = rightSide[start];
    }
    if (start) {
      return 1;
    }
  }
  return 0;
}

void solve() {
  ll i;

  // There are some wormholes havenot get paired yet
  for (i = 1; i <= n; i++) {
    if (pairing[i] == 0) {
      break;
    }
  }

  if (i == n + 1) {
    res += isCycle();
    return;
  }
  // try to pair
  for (ll j = i + 1; j <= n; j++) {
    if (pairing[j] == 0) {
      pairing[i] = j;
      pairing[j] = i;
      solve();
      pairing[j] = 0;
      pairing[i] = 0;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  setIO("wormhole");
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    cin >> X[i] >> Y[i];
  }

  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      if (Y[i] == Y[j] && X[i] < X[j]) {
        if (rightSide[i] == 0 || X[j] - X[i] < X[rightSide[i]] - X[i]) {
          rightSide[i] = j;
        }
      }
    }
  }
  solve();
  cout << res << endl;
}
