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

set<ll> res;
void generate(ll start, pair<ll, vector<ll>> go, pair<ll, vector<ll>> to) {
  if (start == 4) {
    res.insert(go.first);
    return;
  } else {
    for (ll i = 0; i < go.second.size(); i++) {
      ll temp = go.second[i];
      vector<ll> Go = go.second;
      Go.erase(Go.begin() + i);
      vector<ll> To = to.second;
      To.push_back(temp);

      generate(start + 1, {to.first + temp, To}, {go.first - temp, Go});
    }
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  setIO("backforth");
  vector<ll> a(10);
  vector<ll> b(10);

  for (ll i = 0; i < 10; i++)
    cin >> a[i];
  for (ll i = 0; i < 10; i++)
    cin >> b[i];

  generate(0, {1000, a}, {1000, b});

  cout << res.size() << endl;
}
