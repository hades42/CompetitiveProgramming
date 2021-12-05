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
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  // Thien 0
  // Quang 1

  ll turn = 0;
  for (ll i = 0; i < n; i++) {
    ll remain = arr[i] % 3;
    ll go = arr[i] / 3;

    // If this turn Thien go first
    if (turn == 0) {
      if (remain == 0) {
        if (go % 2 == 0) {
          cout << "Quang won!" << endl;
          turn = 0;
        } else {
          cout << "Thien won!" << endl;
          turn = 1;
        }
      } else {
        if (go % 2 == 0) {
          cout << "Thien won!" << endl;
          turn = 1;
        } else {
          cout << "Quang won!" << endl;
          turn = 0;
        }
      }
      continue;
    }
    // If this turn Quang go first
    else {
      if (remain == 0) {
        if (go % 2 == 0) {
          cout << "Thien won!" << endl;
          turn = 1;
        } else {
          cout << "Quang won!" << endl;
          turn = 0;
        }
      } else {
        if (go % 2 == 0) {
          cout << "Quang won!" << endl;
          turn = 0;
        } else {
          cout << "Thien won!" << endl;
          turn = 1;
        }
      }
      continue;
    }
  }
}
