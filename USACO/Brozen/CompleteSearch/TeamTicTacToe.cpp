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
  setIO("tttt");
  vector<string> input(3);
  for (ll i = 0; i < 3; i++) {
    cin >> input[i];
  }
  set<set<char>> one;
  set<set<char>> two;
  // row
  set<char> test;
  for (ll i = 0; i < 3; i++) {
    for (ll j = 0; j < 3; j++) {
      test.insert(input[i][j]);
    }
    if (test.size() == 1) {
      one.insert(test);
    } else if (test.size() == 2) {
      two.insert(test);
    }
    test.clear();
  }

  for (ll i = 0; i < 3; i++) {
    for (ll j = 0; j < 3; j++) {
      test.insert(input[j][i]);
    }
    if (test.size() == 1) {
      one.insert(test);
    } else if (test.size() == 2) {
      two.insert(test);
    }
    test.clear();
  }

  for (ll i = 0; i < 3; i++) {
    test.insert(input[i][i]);
  }
  if (test.size() == 1) {
    one.insert(test);
  } else if (test.size() == 2) {
    two.insert(test);
  }
  test.clear();

  for (ll i = 2; i >= 0; i--) {
    test.insert(input[2 - i][i]);
  }
  if (test.size() == 1) {
    one.insert(test);
  } else if (test.size() == 2) {
    two.insert(test);
  }

  cout << one.size() << endl;
  cout << two.size() << endl;
}
