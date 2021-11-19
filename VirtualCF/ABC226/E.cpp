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

vector<vector<ll>> g;
vector<bool> visited;
ll vertex, edge;

void dfs(ll i) {
  visited[i] = true;
  vertex++;
  for (ll j = 0; j < g[i].size(); j++) {
    edge++;
    if (!visited[g[i][j]]) {
      dfs(g[i][j]);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n, m;
  cin >> n >> m;
  g.resize(n);
  visited.resize(n);
  for (ll i = 0; i < n; i++)
    visited[i] = false;
  for (ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ll ans = 1;
  for (ll i = 0; i < n; i++) {
    if (!visited[i]) {
      vertex = 0;
      edge = 0;
      dfs(i);
      if (edge == 2 * vertex) {
        ans = (ans * 2) % 998244353;
      } else {
        ans = 0;
      }
    }
  }
  cout << ans << endl;
}
