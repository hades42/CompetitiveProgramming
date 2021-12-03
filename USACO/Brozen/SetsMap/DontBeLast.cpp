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
#include <unordered_map>
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
  setIO("notlast");
  int N;
  cin >> N;

  map<string, int> raw;
  for (int i = 0; i < N; i++) {
    string a;
    int b;
    cin >> a >> b;
    raw[a] += b;
  }

  vector<pair<int, string>> cows;
  for (pair<string, int> t : raw) {
    cows.push_back({t.second, t.first});
  }
  sort(cows.begin(), cows.end());

  int ind = 0;
  // only move the pointer if all cows produced some milk, as
  // any unmentioned cows will have produced 0 milk
  if (cows.size() == 7) {
    while (ind < cows.size() && cows[ind].first == cows[0].first) {
      ind++;
    }
  }

  if (ind < cows.size() &&
      (ind + 1 == cows.size() || cows[ind].first != cows[ind + 1].first)) {
    cout << cows[ind].second << endl;
    return 0;
  }
  cout << "Tie" << endl;
}
