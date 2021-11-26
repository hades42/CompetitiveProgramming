#include <algorithm>
#include <array>
#include <climits>
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
  setIO("mowing");

  vector<vector<ll>> arr(2005, vector<ll>(2005, -1));
  ll x = 1000;
  ll y = 1000;
  ll time = 0;
  ll res = INT_MAX;
  arr[1000][1000] = 0;
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    char s;
    ll d;
    cin >> s >> d;
    ll dirX = 0;
    ll dirY = 0;
    if (s == 'S') {
      dirX = 1;
    } else if (s == 'N') {
      dirX = -1;
    } else if (s == 'E') {
      dirY = 1;
    } else if (s == 'W') {
      dirY = -1;
    }

    for (ll i = 0; i < d; i++) {
      time++;
      x += dirX;
      y += dirY;
      if (arr[x][y] != -1) {
        res = min(res, time - arr[x][y]);
      }
      arr[x][y] = time;
    }
  }
  if (res == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << res << endl;
  }
}
