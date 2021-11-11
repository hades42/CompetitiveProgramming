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
  ll poss = n - k + 1;
  ll curr = 0;

  vector<ll> value(n);
  vector<ll> awake(n);

  for (ll i = 0; i < n; i++) {
    cin >> value[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> awake[i];
    if (awake[i]) {
      curr += value[i];
      value[i] = 0;
    }
  }
  vector<ll> prefix(n + 1);
  prefix[0] = 0;
  for (ll i = 1; i <= n; i++) {
    prefix[i] += prefix[i - 1] + value[i - 1];
  }
  ll temp = 0;
  for (ll i = n; i >= k; i--) {
    temp = max(temp, prefix[i] - prefix[i - k]);
  }
  cout << curr + temp << endl;
}
