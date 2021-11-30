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

ll n;
map<string, string> arr;
vector<string> cow{"Bessie", "Buttercup", "Belinda", "Beatrice",
                   "Bella",  "Blue",      "Betsy",   "Sue"};
vector<pair<string, string>> ps;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  setIO("lineup");
  cin >> n;
  sort(cow.begin(), cow.end());
  for (ll i = 0; i < n; i++) {
    string n1, temp, n2;
    cin >> n1 >> temp >> temp >> temp >> temp >> n2;
    ps.push_back(make_pair(n1, n2));
  }
  do {
    bool flag = true;
    for (pair<string, string> p : ps) {
      for (ll i = 0; i < 8; i++) {
        if (i > 0 && i < 7 && p.first == cow[i]) {
          if (cow[i + 1] != p.second && cow[i - 1] != p.second) {
            flag = false;
          }
        }
        if (i == 0 && p.first == cow[i] && cow[i + 1] != p.second) {
          flag = false;
        }
        if (i == 7 && p.first == cow[i] && cow[i - 1] != p.second) {
          flag = false;
        }
      }
    }
    if (flag)
      break;
  } while (next_permutation(cow.begin(), cow.end()));

  for (string c : cow) {
    cout << c << endl;
  }
}
