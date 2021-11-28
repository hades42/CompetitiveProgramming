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
  vector<string> arr(2);
  for (ll i = 0; i < 2; i++) {
    cin >> arr[i];
  }
  vector<vector<char>> ahihi;
  ahihi.resize(4);
  for (ll i = 0; i < 4; i++) {
    for (ll j = 0; j < 4; j++) {
      ahihi[i].push_back('.');
    }
  }
  for (ll i = 0; i < 2; i++) {
    for (ll j = 0; j < 2; j++) {
      ahihi[i + 1][j + 1] = arr[i][j];
    }
  }

  // for (ll i = 0; i < 4; i++) {
  // for (ll j = 0; j < 4; j++) {
  // cout << ahihi[i][j] << " ";
  //}
  // cout << endl;
  //}
  bool flag = true;
  for (ll i = 1; i <= 2; i++) {
    for (ll j = 1; j <= 2; j++) {
      bool test = false;
      test |= (ahihi[i + 1][j] == '#');
      test |= (ahihi[i - 1][j] == '#');
      test |= (ahihi[i][j + 1] == '#');
      test |= (ahihi[i][j - 1] == '#');
      if (!test) {
        flag = false;
      }
    }
  }
  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
