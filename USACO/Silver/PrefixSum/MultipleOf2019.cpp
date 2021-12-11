#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
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
  string s;
  cin >> s;
  vector<ll> remain(2019);
  remain[0] = 1;
  ll pow = 1;
  ll num = 0;
  for (ll i = s.size() - 1; i >= 0; i--) {
    num = (num + pow * (s[i] - '0')) % 2019;
    remain[num]++;
    pow = pow * 10 % 2019;
  }
  ll res = 0;
  for (ll i = 0; i < 2019; i++) {
    res += remain[i] * (remain[i] - 1) / 2;
  }
  cout << res << endl;
}
