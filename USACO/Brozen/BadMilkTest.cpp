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

struct Drink {
  ll m, t, p;
};

struct Sick {
  ll p, t;
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  // setIO("badmilk");
  ll N, M, D, S;
  cin >> N >> M >> D >> S;
  vector<Drink> arr(D);
  vector<Sick> sick(S);
  vector<vector<ll>> drank;
  drank.resize(N + 1);
  for (ll i = 0; i < D; i++) {
    cin >> arr[i].p >> arr[i].m >> arr[i].t;
  }
  for (ll i = 0; i < S; i++) {
    cin >> sick[i].p >> sick[i].t;
  }

  for (ll i = 0; i < D; i++) {
    for (ll j = 0; j < S; j++) {
      if (arr[i].p == sick[j].p && arr[i].t < sick[j].t) {
        drank[arr[i].p].push_back(arr[i].m);
      }
    }
  }

  vector<bool> cmilk(M + 1, true);

  for (ll i = 1; i <= M; i++) {
    for (ll j = 1; j <= N; j++) {
      if (drank[j].size()) {
        bool possible = false;
        for (auto milk : drank[j]) {
          if (milk == i) {
            possible = true;
            break;
          }
        }
        if (!possible) {
          cmilk[i] = false;
        }
      }
    }
  }
  // print2d(drank);
  // print(cmilk);
  vector<bool> isSick(N + 1);
  for (ll i = 1; i < cmilk.size(); i++) {
    for (ll j = 0; j < D; j++) {
      if (cmilk[i]) {
        if (arr[j].m == i) {
          isSick[arr[j].p] = true;
        }
      }
    }
  }

  ll res = 0;
  for (auto check : isSick) {
    if (check)
      res++;
  }
  cout << res << endl;
}
