#include <algorithm>
#include <array>
#include <cctype>
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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll q;
  cin >> q;
  while (q--) {
    string a, b;
    cin >> a >> b;
    vector<vector<ll>> dp(b.size() + 1, vector<ll>(a.size() + 1));
    dp[0][0] = 1;
    for (int i = 1; i < a.size(); i++) {
      if (isupper(a[i - 1])) {
        dp[0][i] = false;
      } else {
        dp[0][i] = dp[0][i - 1];
      }
    }
    for (int i = 1; i < b.size() + 1; i++) {
      for (int j = 1; j < a.size() + 1; j++) {
        if (isupper(a[j - 1])) {
          if (a[j - 1] == b[i - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
          } else {
            dp[i][j] = 0;
          }
        } else {
          // cout << a[j - 1] << " " << b[i - 1] << endl;
          if (toupper(a[j - 1]) == b[i - 1]) {
            dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1];
          } else {
            dp[i][j] = dp[i][j - 1];
          }
        }
      }
    }
    // print2d(dp);
    if (dp[b.size()][a.size()]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
