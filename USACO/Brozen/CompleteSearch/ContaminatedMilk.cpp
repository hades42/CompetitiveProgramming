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
  // setIO("badmilk");
  ll N, M, D, S;
  cin >> N >> M >> D >> S;
  vector<vector<pr>> person;
  person.resize(N + 1);
  map<ll, set<ll>> mp;
  for (ll i = 0; i < D; i++) {
    ll p, m, t;
    cin >> p >> m >> t;
    mp[m].insert(p);
    person[p].push_back(make_pair(m, t));
  }

  vector<ll> cmilk(M + 1);
  // set<ll> sickPerson;
  for (ll i = 0; i < S; i++) {
    ll p, t;
    cin >> p >> t;
    // sickPerson.insert(p);
    vector<pr> per = person[p];
    for (ll i = 0; i < per.size(); i++) {
      if (per[i].second < t) {
        cmilk[per[i].first]++;
      }
    }
  }

  set<ll> res;
  for (ll i = 0; i < cmilk.size(); i++) {
    if (cmilk[i] == S) {
      // res = max(res, (ll)mp[i].size());
      for (auto it = mp[i].begin(); it != mp[i].end(); it++) {
        res.insert(*it);
      }
    }
  }
  print(cmilk);
  cout << res.size() << endl;
}
