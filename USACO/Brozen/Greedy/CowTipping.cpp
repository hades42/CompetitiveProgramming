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

bool checking(vector<string> arr) {
  for (ll i = 0; i < arr.size(); i++) {
    for (ll j = 0; j < arr[i].size(); j++) {
      if (arr[i][j] == '1') {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  setIO("cowtip");
  ll N;
  cin >> N;
  vector<string> cow(N);
  for (ll i = 0; i < N; i++) {
    cin >> cow[i];
  }
  ll res = 0;
  while (!checking(cow)) {
    ll x, y;
    for (ll i = N - 1; i >= 0; i--) {
      bool find = false;
      for (ll j = N - 1; j >= 0; j--) {
        if (cow[i][j] == '1') {
          x = i;
          y = j;
          find = true;
          break;
        }
      }
      if (find) {
        break;
      }
    }
    // cout << x << " " << y << endl;

    for (ll i = 0; i <= x; i++) {
      for (ll j = 0; j <= y; j++) {
        if (cow[i][j] == '0')
          cow[i][j] = '1';
        else
          cow[i][j] = '0';
      }
    }

    // for (ll i = 0; i < cow.size(); i++) {
    // cout << cow[i] << endl;
    //}
    res++;
  }
  cout << res << endl;
}
