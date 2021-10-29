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
  ll n;
  cin >> n;
  vector<pair<string, string>> arr;
  ll noel = 0;
  for (ll i = 0; i < n; i++) {
    string name;
    string have;
    cin >> name >> have;
    if (have == "no")
      noel++;
    arr.push_back(make_pair(name, have));
  }
  for (ll i = 0; i < n; i++) {
    if (arr[i].second == "yes") {
      cout << arr[i].first << " " << noel << endl;
    } else {
      cout << arr[i].first << " " << 0 << endl;
    }
  }
  return 0;
}
