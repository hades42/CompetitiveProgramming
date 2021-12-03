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
  ll n, target;
  cin >> n >> target;
  vector<ll> arr(n);
  map<ll, vector<ll>> mp;
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
    mp[arr[i]].push_back(i + 1);
  }
  for (ll i = 0; i < n; i++) {
    ll curr = arr[i];
    if (mp.find(target - curr) != mp.end()) {
      if (curr == target - curr && mp[target - curr].size() > 1) {
        cout << mp[curr][0] << " " << mp[curr][1] << endl;
        return 0;
      }
      if (curr != target - curr) {
        cout << mp[curr][0] << " " << mp[target - curr][0] << endl;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
