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
  setIO("cownomics");
  ll n, m;
  cin >> n >> m;
  vector<string> spoty(n);
  vector<string> clean(n);
  for (ll i = 0; i < n; i++) {
    cin >> spoty[i];
  }

  for (ll i = 0; i < n; i++) {
    cin >> clean[i];
  }

  ll res = 0;
  set<string> test;
  for (ll i = 0; i < m; i++) {
    for (ll j = i + 1; j < m; j++) {
      for (ll z = j + 1; z < m; z++) {
        test.clear();
        string temp = "ahi";
        for (ll h = 0; h < n; h++) {
          temp[0] = spoty[h][i];
          temp[1] = spoty[h][j];
          temp[2] = spoty[h][z];

          test.insert(temp);
        }

        bool flag = true;
        string temp2 = "ahi";
        for (ll h = 0; h < n; h++) {
          temp2[0] = clean[h][i];
          temp2[1] = clean[h][j];
          temp2[2] = clean[h][z];

          if (test.count(temp2)) {
            flag = false;
          }
        }

        if (flag) {
          res++;
        }
      }
    }
  }
  cout << res << endl;
}
