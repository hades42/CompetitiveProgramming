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

vector<vector<ll>> graph;
vector<bool> visited;
vector<ll> grass;

// void dfs(ll curr, ll parent) {
// ll g = 1;
// visited[curr] = true;
// for (ll i : graph[curr]) {
// if (!visited[i]) {
// while (grass[curr] == g || g == grass[parent]) {
// g++;
//}
// grass[i] = g;
// dfs(i, curr);
// g++;
//}
//}
//}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  setIO("planting");
  ll n;
  cin >> n;
  // graph.resize(n);
  vector<ll> degree(n);
  for (ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    // graph[u].push_back(v);
    // graph[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }
  ll ans = 0;
  for (ll num : degree) {
    ans = max(ans, num);
  }
  cout << ans + 1 << endl;
  // grass.resize(n);
  // visited.resize(n);
  // for (ll i = 0; i < n; i++) {
  // grass[i] = 1;
  // visited[i] = false;
  //}
  // dfs(0, 0);
  // ll ans = 0;
  // for (ll num : grass) {
  // ans = max(num, ans);
  //}
  // cout << ans << endl;
}
