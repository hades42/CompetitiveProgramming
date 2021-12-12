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

vector<vector<ll>> G;
map<ll, ll> mp;
vector<bool> seen;

void dfs(ll u, ll pu) {
  seen[u] = true;
  for (ll v : G[u]) {
    if (v == pu)
      continue;
    if (seen[v]) {
      cout << "No" << endl;
      exit(0);
    } else {
      dfs(v, u);
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  ll n, q;
  cin >> n >> q;
  G.resize(n + 1);
  seen.resize(n + 1);
  for (ll i = 0; i <= n; i++)
    seen[i] = false;
  bool flag = true;
  for (ll i = 0; i < q; i++) {
    ll a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
    mp[a]++;
    mp[b]++;
  }
  for (auto pi : mp) {
    if (pi.second > 2) {
      cout << "No" << endl;
      return 0;
    }
  }

  for (ll i = 1; i <= q; i++) {
    if (!seen[i]) {
      dfs(i, -1);
    }
  }
  cout << "Yes" << endl;
}
