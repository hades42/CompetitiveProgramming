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
vector<ll> pasture;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  setIO("revegetate");
  ll n, m;
  cin >> n >> m;
  graph.resize(n);
  pasture.resize(n);
  for (ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (ll i = 0; i < n; i++)
    pasture[i] = 0;
  for (ll i = 0; i < n; i++) {
    set<ll> check;
    for (ll i : graph[i]) {
      check.insert(pasture[i]);
    }
    for (ll choice = 1; choice <= 4; choice++) {
      if (!check.count(choice)) {
        pasture[i] = choice;
        break;
      }
    }
  }
  for (ll num : pasture) {
    cout << num;
  }
}
