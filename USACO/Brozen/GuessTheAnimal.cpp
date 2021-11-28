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
  setIO("guess");
  ll n;
  cin >> n;
  vector<set<string>> arr;
  arr.resize(n);
  for (ll i = 0; i < n; i++) {
    string name;
    ll amount;
    cin >> name >> amount;
    for (ll j = 0; j < amount; j++) {
      string ch;
      cin >> ch;
      arr[i].insert(ch);
    }
  }
  ll res = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = i + 1; j < n; j++) {
      ll temp = 0;
      for (string charac : arr[i]) {
        if (arr[j].count(charac)) {
          temp++;
        }
      }
      res = max(temp, res);
    }
  }
  cout << res + 1 << endl;
}
