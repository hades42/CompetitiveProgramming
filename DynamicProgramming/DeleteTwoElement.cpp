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
  ll n;
  cin >> n;
  ll sum = 0;
  map<ll, ll> m;
  vector<ll> arr(n);
  for (ll i = 0; i < n; i++) {
    ll num;
    cin >> num;
    m[num]++;
    arr[i] = num;
    sum += num;
  }
  ll check = (2 * sum) % n;
  if (check != 0) {
    cout << 0 << endl;
    return;
  }
  ll need = (2 * sum) / n;
  ll res = 0;
  for (ll i = 0; i < n; i++) {
    ll curr = arr[i];
    ll find = need - curr;
    if (m[find])
      res += m[find];
    if (find == curr)
      res -= 1;
  }
  cout << res / 2 << endl;
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
