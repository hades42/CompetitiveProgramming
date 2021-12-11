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
  setIO("hps");
  ll n;
  cin >> n;
  // 0 -> P
  // 1 -> H
  // 2 -> S
  vector<vector<ll>> arr(n + 1, vector<ll>(3));
  for (ll i = 1; i <= n; i++) {
    char play;
    cin >> play;
    arr[i][0] = arr[i - 1][0];
    arr[i][1] = arr[i - 1][1];
    arr[i][2] = arr[i - 1][2];
    if (play == 'P') {
      arr[i][0] += 1;
    } else if (play == 'H') {
      arr[i][1] += 1;
    } else {
      arr[i][2] += 1;
    }
  }
  ll res = 0;
  for (ll i = 1; i < n; i++) {
    ll first = max({arr[i][0], arr[i][1], arr[i][2]});
    ll second = max(
        {arr[n][0] - arr[i][0], arr[n][1] - arr[i][1], arr[n][2] - arr[i][2]});
    res = max(res, first + second);
  }
  cout << res << endl;
}
