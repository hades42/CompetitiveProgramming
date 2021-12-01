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
  vector<tuple<ll, string, ll>> pos;
  setIO("measurement");
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    ll day;
    string name;
    ll value;
    cin >> day >> name >> value;
    pos.push_back(make_tuple(day, name, value));
  }
  sort(pos.begin(), pos.end());
  vector<ll> arr(3, 7);
  vector<bool> top(3, true);
  ll change = 0;
  // E -> 0
  // M -> 1
  // B -> 2
  string curr;
  ll res = 0;
  for (ll i = 0; i < n; i++) {
    if (get<1>(pos[i]) == "Mildred") {
      arr[1] += get<2>(pos[i]);
    } else if (get<1>(pos[i]) == "Elsie") {
      arr[0] += get<2>(pos[i]);
    } else {
      arr[2] += get<2>(pos[i]);
    }
    ll mx = -INF;
    for (ll i = 0; i < n; i++) {
      mx = max(mx, arr[i]);
    }
    vector<bool> newTop(3);

    for (ll i = 0; i < 3; i++) {
      newTop[i] = (arr[i] == mx);
    }
    if (top != newTop) {
      res++;
      top = newTop;
    }
  }
  cout << res << endl;
}
