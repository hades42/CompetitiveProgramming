#include <algorithm>
#include <array>
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
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  set<char> st;
  for (ll i = 0; i < k; i++) {
    char avai;
    cin >> avai;
    st.insert(avai);
  }
  vector<ll> dp(n);
  if (st.count(s[0])) {
    dp[0] = 1;
  } else {
    dp[0] = 0;
  }
  // print(dp);
  ll ans = 0;
  for (ll i = 1; i < n; i++) {
    if (st.count(s[i])) {
      dp[i] = dp[i - 1] + 1;
    } else {
      dp[i] = 0;
      ans += dp[i - 1] * (dp[i - 1] + 1) / 2;
    }
  }
  ans += dp[n - 1] * (dp[n - 1] + 1) / 2;
  // print(dp);
  cout << ans << endl;
}
