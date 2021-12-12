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
#include <sstream>
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

map<string, vector<string>> G;
map<string, bool> seen;
ll ans = 0;

bool checkLower(string s) {
  for (ll i = 0; i < s.size(); i++) {
    if (islower(s[i])) {
      return true;
    }
  }
  return false;
}

void search(string u) {
  if (u == "end") {
    ans++;
    return;
  }
  if (checkLower(u)) {
    seen[u] = true;
  }
  for (ll i = 0; i < G[u].size(); i++) {
    if (seen[u])
      continue;
    search(G[u][i]);
  }
}

int main() {
  string line;
  while (getline(cin, line)) {
    ll i;
    for (i = 0; i < line.size(); i++) {
      if (line[i] == '-') {
        break;
      }
    }
    string first = line.substr(0, i);
    string second = line.substr(i + 1);
    G[first].push_back(second);
    G[second].push_back(first);
  }

  // for (auto pi : G) {
  // cout << pi.first << " -> ";
  // for (string v : G[pi.first]) {
  // cout << v << " ";
  //}
  // cout << endl;
  //}

  set<string> special;
  special.insert("start");
  special.insert("end");

  set<string> small;
  small.insert("start");
  tuple<string, set<string>, bool> start = {"start", small, false};
  queue<tuple<string, set<string>, bool>> Q;
  Q.push(start);
  while (!Q.empty()) {
    auto curr = Q.front();
    Q.pop();
    for (auto el : get<1>(curr)) {
      cout << el << " ";
    }
    cout << endl;
    if (get<0>(curr) == "end") {
      ans++;
      continue;
    }
    for (string v : G[get<0>(curr)]) {
      if (!get<1>(curr).count(v)) {
        set<string> newSet(get<1>(curr));
        if (checkLower(v)) {
          newSet.insert(v);
        }
        Q.push({v, newSet, get<2>(curr)});
      } else if (get<1>(curr).count(v) && get<2>(curr) == false &&
                 !special.count(v)) {
        Q.push({v, get<1>(curr), true});
      }
    }
  }
  cout << ans << endl;
}
