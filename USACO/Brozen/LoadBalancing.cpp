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
  setIO("balancing");
  ll n, b;
  cin >> n >> b;
  vector<pr> arr(n);
  set<ll> X;
  set<ll> Y;

  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    arr[i] = make_pair(x, y);
    X.insert(x + 1);
    Y.insert(y + 1);
  }
  ll res = INF;
  for (auto itX = X.begin(); itX != X.end(); itX++) {
    for (auto itY = Y.begin(); itY != Y.end(); itY++) {
      ll currX = *itX;
      ll currY = *itY;

      vector<ll> pos(4);
      ll temp = 0;
      for (ll i = 0; i < n; i++) {
        ll x = arr[i].first;
        ll y = arr[i].second;

        if (x < currX && y > currY) {
          pos[0]++;
        }

        if (x > currX && y > currY) {
          pos[1]++;
        }

        if (x > currX && y < currY) {
          pos[2]++;
        }

        if (x < currX && y < currY) {
          pos[3]++;
        }
      }

      for (auto num : pos)
        temp = max(temp, num);
      res = min(res, temp);
    }
  }
  cout << res << endl;
}
