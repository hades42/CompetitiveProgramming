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

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<string> matrix(n);
  for (ll i = 0; i < n; i++) {
    cin >> matrix[i];
  }
  vector<vector<ll>> path(n, vector<ll>(m));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      if (matrix[i][j] == '.')
        continue;
      ll d = 0;
      while (1) {
        if (i - d < 0 || j - d < 0 || j + d >= m) {
          break;
        }
        if (matrix[i - d][j - d] != '*')
          break;
        if (matrix[i - d][j + d] != '*')
          break;

        d++;
      }
      path[i][j] = d - 1;
    }
  }
  ll flag = true;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      if (matrix[i][j] == '.')
        continue;
      ll d = 0;
      bool find = 0;
      while (1) {
        // Check for the root
        if (i + d >= n)
          break;

        // Come from the root -> right
        if (j - d < m && j - d >= 0) {
          if (path[i + d][j - d] >= k && path[i + d][j - d] >= d) {
            find = 1;
            break;
          }
        }

        // Come from the root -> left
        if (j + d < m && j + d >= 0) {
          if (path[i + d][j + d] >= k && path[i + d][j + d] >= d) {
            find = 1;
            break;
          }
        }
        d++;
      }
      flag &= find;
    }
  }
  if (flag) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
