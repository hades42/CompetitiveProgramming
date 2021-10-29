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

void solve() {
  string s;
  cin >> s;
  bool anyZero = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      anyZero = true;
      break;
    }
  }
  ll nZero = 0;
  if (s[0] == '0')
    nZero++;
  for (ll i = 1; i < s.size(); i++) {
    if (s[i] == '0' && s[i - 1] == '1')
      nZero++;
  }
  if (!anyZero) {
    cout << 0 << endl;
  } else if (nZero == 1) {
    cout << 1 << endl;
  } else {
    cout << 2 << endl;
  }
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
