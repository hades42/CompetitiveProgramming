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

ll pow(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1)
      ans = (ans * a);
    b /= 2;
    a = (a * a);
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll L, R;
  cin >> L >> R;
  vector<ll> arr(R + 1);
  set<ll> cb;
  ll square = 0;
  ll cube = 0;
  ll special = 0;
  for (ll i = 1; i <= 1e9; i++) {
    ll p2 = pow(i, 2);
    ll p3 = pow(i, 3);
    if (p2 > R) {
      break;
    }
    if (p2 <= R && p2 >= L) {
      square++;
    }
    if (p3 <= R && p3 >= L) {
      cube++;
      cb.insert(p3);
    }
    if (cb.count(p2)) {
      special++;
    }
  }
  cout << square << " " << cube << " " << special << endl;
}
