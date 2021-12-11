#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <numeric>
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

vector<vector<ll>> arr;
ll R;
ll C;

ll ans = 0;
void flash(ll x, ll y) {
  ans++;
  arr[x][y] = -1;
  vector<ll> dr{-1, 0, 1};
  vector<ll> dc{-1, 0, 1};
  for (ll i = 0; i < dr.size(); i++) {
    for (ll j = 0; j < dc.size(); j++) {
      ll rr = x + dr[i];
      ll cc = y + dc[j];
      if (rr >= 0 && rr < R && cc >= 0 && cc < C && arr[rr][cc] != -1) {
        arr[rr][cc] += 1;
        if (arr[rr][cc] >= 10) {
          flash(rr, cc);
        }
      }
    }
  }
}

int main() {
  string line;
  while (getline(cin, line)) {
    vector<ll> temp(line.size());
    for (ll i = 0; i < line.size(); i++) {
      temp[i] = line[i] - '0';
    }
    arr.push_back(temp);
  }
  // print2d(arr);

  R = arr.size();
  C = arr[0].size();

  cout << R << " " << C << endl;
  for (ll step = 1;; step++) {
    for (ll i = 0; i < R; i++) {
      for (ll j = 0; j < C; j++) {
        if (arr[i][j] == -1)
          continue;
        arr[i][j] += 1;
        if (arr[i][j] == 10) {
          flash(i, j);
        }
      }
    }
    ll count = 0;
    for (ll i = 0; i < R; i++) {
      for (ll j = 0; j < C; j++) {
        if (arr[i][j] == -1) {
          count++;
          arr[i][j] = 0;
        }
      }
    }
    if (count == R * C) {
      cout << step << endl;
      return 0;
    }
    print2d(arr);
  }

  cout << ans << endl;
}
