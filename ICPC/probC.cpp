#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <utility>
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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n, c;
  cin >> n >> c;
  map<char, ll> mp;
  ll consecutive = 0;
  string first;
  pair<ll, ll> res = make_pair(0, 0);
  vector<pair<ll, ll>> ans;
  for (ll i = 0; i < n; i++) {
    string in;
    cin >> in;
    set<char> st;
    for (ll j = 0; j < in.size() && j < c; j++) {
      st.insert(in[j]);
      mp[in[j]]++;
      consecutive = max(consecutive, mp[in[j]]);
    }
    if (i > 0) {
      for (ll j = 0; j < first.size() && j < c; j++) {
        if (!st.count(first[j])) {
          mp[first[j]] = 0;
        }
      }
    }
    ll temp = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
      // cout << it->first << " " << it->second << endl;
      if (it->second == consecutive) {
        temp++;
      }
    }
    ans.push_back(make_pair(consecutive, temp));
    // cout << consecutive << " " << temp << endl;
    first = in;
  }
  sort(ans.begin(), ans.end());
  cout << ans[ans.size() - 1].first << " " << ans[ans.size() - 1].second
       << endl;
}
