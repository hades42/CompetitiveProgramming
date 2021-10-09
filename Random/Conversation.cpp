#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
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
  ll n;
  cin >> n;
  map<string, map<string, ll>> words;
  map<string, ll> wordCount;
  string s;
  for (ll i = 0; i < n; i++) {
    getline(cin, s);
    istringstream iss(s);
    ll count = 0;
    string user;
    do {
      if (count == 0) {
        iss >> user;
      } else {
        string subs;
        iss >> subs;
        words[user][subs]++;
      }
      count++;
    } while (iss);
  }
  cout << endl;
  vector<string> result;
  for (auto x : words) {
    cout << x.first << ": ";
    for (auto y : words[x.first]) {
      cout << y.first << " ";
      if (y.second > 1) {
        result.push_back(y.first);
      }
    }
    cout << endl;
  }
}
