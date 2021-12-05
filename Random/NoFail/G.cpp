#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define ll long long
#define F first
#define S second
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

int dist[1005][1005];
ll n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isvalid(vector<string> grid, int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '*';
}

int minDist(vector<string> grid, int i, int j) {
  queue<pair<int, int>> q;
  q.push({i, j});
  dist[i][j] = 0;
  while (!q.empty()) {
    i = q.front().F;
    j = q.front().S;
    // cout << i << " " << j << endl;
    if (grid[i][j] == 'e')
      return dist[i][j];
    q.pop();
    for (int k = 0; k < 4; k++) {
      int u = i + dx[k];
      int v = j + dy[k];
      if (isvalid(grid, u, v)) {
        // cout << u << " " << v << endl;
        if (dist[u][v] == -1) {
          dist[u][v] = dist[i][j] + 1;
          q.push({u, v});
        }
      }
    }
  }
  return -1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> m;
  ll startx;
  ll starty;
  vector<string> grid(n);
  for (ll i = 0; i < n; i++) {
    cin >> grid[i];
  }
  memset(dist, -1, sizeof dist);
  for (ll i = 0; i < n; i++) {
    bool flag = false;
    for (ll j = 0; j < m; j++) {
      if (grid[i][j] == 's') {
        startx = i;
        starty = j;
        flag = true;
        break;
      }
    }
    if (flag) {
      break;
    }
  }
  ll res = minDist(grid, startx, starty);
  if (res != -1) {
    cout << res << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
}
