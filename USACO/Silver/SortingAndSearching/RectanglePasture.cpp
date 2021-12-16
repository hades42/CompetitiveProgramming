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

bool comp(pr a, pr b) { return a.second < b.second; }

vector<vector<ll>> prefixSum;

ll rSum(ll x1, ll y1, ll x2, ll y2) {
  return prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] +
         prefixSum[x1 - 1][y1 - 1];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n;
  cin >> n;
  vector<pr> arr(n);
  for (ll i = 0; i <= n; i++) {
    vector<ll> temp(n + 1);
    prefixSum.push_back(temp);
  }
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    arr[i] = {a, b};
  }
  sort(arr.begin(), arr.end());

  for (ll i = 0; i < n; i++)
    arr[i].first = i + 1;
  sort(arr.begin(), arr.end(), comp);
  for (ll i = 0; i < n; i++) {
    arr[i].second = i + 1;
  }
  // for (auto el : arr) {
  // cout << el.first << " " << el.second << endl;
  //}

  for (auto el : arr) {
    prefixSum[el.first][el.second] = 1;
  }

  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      prefixSum[i][j] +=
          prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
    }
  }

  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      ll x1 = min(arr[i].first, arr[i].second);
      ll x2 = max(arr[i].first, arr[i].second);
      ans += rSum(1, i + 1, x1, j + 1) * rSum(x2, i + 1, n, j + 1);
    }
  }
  cout << ans << endl;
}
