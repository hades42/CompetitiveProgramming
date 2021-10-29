#include <algorithm>
#include <array>
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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll t;
  cin >> t;
  while (t--) {
    vector<ll> arr(3);
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
      ll num;
      cin >> num;
      arr[num]++;
      sum += num;
    }
    if (sum % 2 != 0) {
      cout << "NO" << endl;
    } else {
      if (arr[1] == 0) {
        if (arr[2] % 2 == 0) {
          cout << "YES" << endl;
        } else
          cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
}
