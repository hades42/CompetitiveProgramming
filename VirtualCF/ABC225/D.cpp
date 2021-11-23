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
  ll n, q;
  cin >> n >> q;
  vector<ll> front(n + 1);
  vector<ll> back(n + 1);
  for (ll i = 0; i < q; i++) {
    ll m;
    cin >> m;
    if (m == 1) {
      ll x, y;
      cin >> x >> y;
      front[y] = x;
      back[x] = y;
    } else if (m == 2) {
      ll x, y;
      cin >> x >> y;
      back[x] = 0;
      front[y] = 0;
    } else if (m == 3) {
      ll x;
      cin >> x;
      while (front[x] != 0) {
        x = front[x];
      }
      vector<ll> res;
      while (x != 0) {
        res.push_back(x);
        x = back[x];
      }
      cout << res.size() << " ";
      print(res);
    }
  }
}
