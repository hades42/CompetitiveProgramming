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

ll gcd(ll a, ll b) {
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  if (a > b) {
    return gcd(a - b, b);
  } else {
    return gcd(a, b - a);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n;
  cin >> n;
  vector<pr> arr;
  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    arr.push_back(make_pair(x, y));
  }
  set<pr> s;
  for (ll i = 0; i < n; i++) {
    pr curr = arr[i];
    for (ll j = 0; j < n; j++) {
      if (i == j)
        continue;
      pr next = arr[j];
      ll diffX = curr.first - next.first;
      ll diffY = curr.second - next.second;
      ll same = gcd(abs(diffX), abs(diffY));
      s.insert(make_pair(diffX / same, diffY / same));
    }
  }
  // for (auto it = s.begin(); it != s.end(); it++) {
  // cout << (*it).first << " " << (*it).second << endl;
  //}
  cout << s.size() << endl;
}
