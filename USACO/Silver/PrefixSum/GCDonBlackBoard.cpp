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

// ll gcd(ll a, ll b) {
// if (a == 0)
// return b;
// if (b == 0)
// return a;

// if (a == b)
// return a;
// if (a > b) {
// return gcd(a - b, b);
//} else {
// return gcd(a, b - a);
//}
//}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll N;
  cin >> N;
  vector<ll> arr(N + 1);
  for (ll i = 1; i <= N; i++) {
    cin >> arr[i];
  };
  vector<ll> preSum(N + 2);
  vector<ll> sufSum(N + 2);
  preSum[0] = 0;
  sufSum[N + 1] = 0;
  for (ll i = 1; i <= N; i++) {
    preSum[i] = gcd(preSum[i - 1], arr[i]);
  }

  for (ll i = N; i >= 1; i--) {
    sufSum[i] = gcd(sufSum[i + 1], arr[i]);
  }

  ll res = 0;
  for (ll i = 1; i <= N; i++) {
    res = max(res, gcd(sufSum[i + 1], preSum[i - 1]));
  }
  cout << res << endl;
}
