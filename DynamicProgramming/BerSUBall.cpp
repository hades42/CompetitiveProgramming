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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  };
  ll m;
  cin >> m;
  vector<ll> b(m);
  for (ll i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll i, j;
  i = j = 0;
  ll count = 0;
  while (i < n && j < m) {
    if (abs(a[i] - b[j]) <= 1) {
      count++;
      i++;
      j++;
    } else {
      if (a[i] < b[j]) {
        i++;
      } else {
        j++;
      }
    }
  }
  cout << count << endl;
}
