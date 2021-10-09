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
  ll count = 0;
  map<ll, set<ll>> m;
  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    m[x].insert(y);
  }
  set<ll> form;
  for (auto it = m.begin(); it != m.end(); it++) {
    for (auto it2 = m.begin(); it2 != m.end(); it2++) {
      if (it->first == it2->first)
        continue;
      set<ll> curr = it->second;
      set<ll> check = it2->second;
      ll currCount = 0;
      for (auto s = curr.begin(); s != curr.end(); s++) {
        ll currY = *s;
        if (check.count(currY)) {
          currCount++;
        }
      }
      // cout << currCount << endl;
      if (currCount >= 2) {
        currCount -= 1;
        form.insert(it->first);
        form.insert(it2->first);
      } else {
        currCount = 0;
      }
      count += currCount;
    }
    // cout << endl;
  }
  // cout << endl;
  // cout << count << " " << form.size() << endl;
  if (form.size()) {
    cout << count / 2 << endl;
  } else {
    cout << 0 << endl;
  }
  // cout << form.size() << endl;
}
