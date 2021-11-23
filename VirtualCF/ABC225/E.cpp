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

struct fraction {
  ll y, x;
  fraction(ll Y = 0, ll X = 1) : y(Y), x(X){};
  bool operator<(const fraction &other) const {
    return y * other.x < x * other.y;
  }
  bool operator<=(const fraction &other) const {
    return y * other.x <= x * other.y;
  }
};

// struct fraction {
// ll p, q;
// fraction(ll P = 0, ll Q = 1) : p(P), q(Q) {}
// bool operator<(const fraction &other) const {
// return p * other.q < other.p * q;
//}
// bool operator<=(const fraction &other) const {
// return p * other.q <= other.p * q;
//}
//};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n;
  cin >> n;
  vector<ll> x(n), y(n);
  for (ll i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<pair<fraction, fraction>> arr(n);
  for (ll i = 0; i < n; i++) {
    arr[i] = make_pair(fraction(y[i], x[i] - 1), fraction(y[i] - 1, x[i]));
  }
  sort(arr.begin(), arr.end());
  fraction curr;
  ll res = 0;
  for (auto p : arr) {
    if (curr <= p.second) {
      res++;
      curr = p.first;
    }
  }
  cout << res << endl;
}
