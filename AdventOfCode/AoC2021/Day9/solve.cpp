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

vector<vector<ll>> lava;
int main() {
  string line;
  ll count = 0;
  ll n;
  while (getline(cin, line)) {
    n = line.size();
    vector<ll> temp(n + 2, 11);
    if (count == 0) {
      lava.push_back(temp);
    }
    for (ll i = 1; i <= n; i++) {
      temp[i] = line[i - 1] - '0';
    }
    lava.push_back(temp);
    count++;
  }
  vector<ll> temp(n + 2, 11);
  lava.push_back(temp);

  ll res = 0;
  for (ll i = 1; i < lava.size(); i++) {
    for (ll j = 1; j <= n; j++) {
      if (lava[i][j] < lava[i - 1][j] && lava[i][j] < lava[i + 1][j] &&
          lava[i][j] < lava[i][j - 1] && lava[i][j] < lava[i][j + 1]) {
        res += lava[i][j] + 1;
      }
    }
  }
  vector<ll> R{-1, 0, 1, 0};
  vector<ll> C{0, 1, 0, -1};

  vector<ll> ans;
  set<pr> seen;
  ll size;
  for (ll i = 1; i < lava.size(); i++) {
    for (ll j = 1; j <= n; j++) {
      if (!seen.count({i, j}) && lava[i][j] != 9) {
        size = 0;
        queue<pr> q;
        q.push({i, j});
        while (!q.empty()) {
          pr pi = q.front();
          q.pop();
          if (seen.count({pi.first, pi.second}))
            continue;
          seen.insert({pi.first, pi.second});
          size += 1;
          for (ll z = 0; z < 4; z++) {
            ll x = pi.first;
            ll y = pi.second;
            x += R[z];
            y += C[z];
            if (1 <= x && x < lava.size() && 1 <= y && y <= n &&
                lava[x][y] != 9 && lava[x][y] != 11) {
              q.push({x, y});
            }
          }
        }
        ans.push_back(size);
      }
    }
  }
  sort(ans.rbegin(), ans.rend());
  cout << ans[0] * ans[1] * ans[2] << endl;
}
