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

bool check(ll num, ll d) {
  ll find = false;
  while (num > 0) {
    ll curr = num % 10;
    if (curr == d) {
      find = true;
      break;
    }
    num /= 10;
  }
  if (find)
    return true;
  else
    return false;
}

void solve() {
  ll q, d;
  cin >> q >> d;
  for (ll i = 0; i < q; i++) {
    ll num;
    cin >> num;
    if (check(num, d)) {
      cout << "YES" << endl;
    } else {
      bool find = false;
      while (num > 0) {
        num -= d;
        if (check(num, d)) {
          find = true;
          break;
        }
      }
      if (find)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
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
