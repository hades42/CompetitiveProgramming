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
  setIO("div7");
  ll n;
  cin >> n;
  vector<ll> prefix(n + 1);
  for (ll i = 1; i <= n; i++) {
    ll num;
    cin >> num;
    prefix[i] = (num + prefix[i - 1]) % 7;
  }
  vector<ll> pos(n + 1);
  for (auto &num : pos)
    num = -1;
  ll res = 0;
  for (ll i = 1; i <= n; i++) {
    if (pos[prefix[i]] == -1) {
      pos[prefix[i]] = i;
    } else {
      res = max(res, i - pos[prefix[i]]);
    }
  }
  cout << res << endl;
}
