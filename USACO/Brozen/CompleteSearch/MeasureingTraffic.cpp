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
  setIO("traffic");
  ll n;
  cin >> n;
  vector<ll> low(n);
  vector<ll> high(n);
  vector<string> type(n);
  for (ll i = 0; i < n; i++) {
    cin >> type[i] >> low[i] >> high[i];
  }
  ll bLow = -INF;
  ll bHigh = INF;
  for (ll i = n - 1; i >= 0; i--) {
    if (type[i] == "none") {
      bLow = max(bLow, low[i]);
      bHigh = min(bHigh, high[i]);
    }
    if (type[i] == "on") {
      bLow -= high[i];
      bHigh -= low[i];
    }
    if (type[i] == "off") {
      bLow += low[i];
      bHigh += high[i];
    }
  }

  ll aLow = -INF;
  ll aHigh = INF;
  for (ll i = 0; i < n; i++) {
    if (type[i] == "none") {
      aLow = max(aLow, low[i]);
      aHigh = min(aHigh, high[i]);
    }
    if (type[i] == "on") {
      aLow += low[i];
      aHigh += high[i];
    }
    if (type[i] == "off") {
      aLow -= high[i];
      aHigh -= low[i];
    }
  }
  cout << max((ll)0, bLow) << " " << bHigh << endl;
  cout << max((ll)0, aLow) << " " << aHigh << endl;
}
