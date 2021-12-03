#include <algorithm>
#include <array>
#include <cstdio>
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

void setIO(string s) { // the argument is the filename without the extension
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll k, n;
  cin >> k >> n;
  vector<ll> mark(k + 1);
  for (ll i = 1; i <= k; i++) {
    ll num;
    cin >> num;
    mark[i] = mark[i - 1] + num;
  }
  vector<ll> rated(n);
  for (ll i = 0; i < n; i++)
    cin >> rated[i];

  set<ll> num;
  for (ll i = 1; i <= k; i++) {
    num.insert(rated.front() - mark[i]);
  }

  ll res = 0;
  for (auto &x : num) {
    bool flag = true;
    ll curr = x;
    set<ll> temp;
    for (ll i = 1; i <= k; i++) {
      temp.insert(curr + mark[i]);
    }

    for (ll i = 0; i < n; i++) {
      if (!temp.count(rated[i])) {
        flag = false;
        break;
      }
    }
    if (flag) {
      res++;
    }
  }
  cout << res << endl;
}
