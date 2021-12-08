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

vector<vector<string>> cow;
vector<string> charac;

bool check(ll A, ll B) {
  ll aNotB = false;
  ll bNotA = false;
  ll both = false;
  for (ll i = 0; i < cow.size(); i++) {
    bool hasA = false;
    bool hasB = false;
    for (ll j = 0; j < cow[i].size(); j++) {
      if (cow[i][j] == charac[A]) {
        hasA = true;
      }
      if (cow[i][j] == charac[B]) {
        hasB = true;
      }
    }
    if (hasA && !hasB) {
      aNotB = true;
    }
    if (hasB && !hasA) {
      bNotA = true;
    }
    if (hasA && hasB) {
      both = true;
    }
  }

  if (aNotB && bNotA && both) {
    return true;
  } else {
    return false;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  setIO("evolution");
  ll num;
  cin >> num;
  cow.resize(num);
  for (ll i = 0; i < num; i++) {
    ll k;
    cin >> k;
    for (ll j = 0; j < k; j++) {
      string temp;
      cin >> temp;
      cow[i].push_back(temp);
      if (find(charac.begin(), charac.end(), temp) == charac.end()) {
        charac.push_back(temp);
      }
    }
  }

  for (ll i = 0; i < charac.size(); i++) {
    for (ll j = i + 1; j < charac.size(); j++) {
      if (check(i, j)) {
        cout << "no" << endl;
        return 0;
      }
    }
  }
  cout << "yes" << endl;
}
