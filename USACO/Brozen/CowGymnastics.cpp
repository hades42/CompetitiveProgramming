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
  setIO("gymnastics");
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> arr(n, vector<ll>(k));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < k; j++) {
      cin >> arr[i][j];
    }
  }
  set<pr> s;
  for (ll i = 0; i < k - 1; i++) {
    for (ll j = i + 1; j < k; j++) {
      s.insert(make_pair(arr[0][i], arr[0][j]));
    }
  }

  for (ll i = 1; i < n; i++) {
    for (ll z = 0; z < k - 1; z++) {
      for (ll j = z + 1; j < k; j++) {
        s.erase(make_pair(arr[i][j], arr[i][z]));
      }
    }
  }
  // for (auto it = s.begin(); it != s.end(); it++) {
  // pr temp = *it;
  // cout << temp.first << " " << temp.second << endl;
  //}
  cout << s.size() << endl;
}
