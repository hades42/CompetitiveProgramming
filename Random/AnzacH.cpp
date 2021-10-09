#include <algorithm>
#include <array>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
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
  for (ll i = 0; i < n; i++) {
    string c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    bool find = false;
    for (ll i = 0; i < 4; i++) {
      // cout << c1[i] << " " << c2[i] << " " << c3[i] << endl;
      if (c1[i] == c2[i] && c2[i] == c3[i]) {
        find = true;
      } else if (c1[i] == c2[i] && c1[i] != c3[i]) {
        find = false;
        break;
      } else if (c1[i] == c3[i] && c1[i] != c2[i]) {
        find = false;
        break;
      } else if (c2[i] == c3[i] && c1[i] != c2[i]) {
        find = false;
        break;
      }
    }
    if (find) {
      cout << "Set" << endl;
    } else {
      cout << "Not a set" << endl;
    }
  }
}
