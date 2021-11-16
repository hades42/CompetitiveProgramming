#include <algorithm>
#include <array>
#include <climits>
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

void solve() {
  string input;
  cin >> input;
  ll res = INT_MAX;
  for (ll i = 0; i < input.length(); i++) {
    for (ll j = i + 1; j < input.length(); j++) {
      if (input[i] == '0' && input[j] == '0') {
        res = min(res, (ll)input.length() - i - 2);
      }
      if (input[i] == '2' && input[j] == '5') {
        res = min(res, (ll)input.length() - i - 2);
      }
      if (input[i] == '5' && input[j] == '0') {
        res = min(res, (ll)input.length() - i - 2);
      }
      if (input[i] == '7' && input[j] == '5') {
        res = min(res, (ll)input.length() - i - 2);
      }
    }
  }
  cout << res << endl;
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
