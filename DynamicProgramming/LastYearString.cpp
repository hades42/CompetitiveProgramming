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

void solve() {
  ll n;
  cin >> n;
  string in;
  cin >> in;
  string match = "2020";
  if (in[0] == '2' && in[1] == '0' && in[2] == '2' && in[3] == '0') {
    cout << "YES" << endl;
    return;
  }

  if (in[0] == '2' && in[n - 3] == '0' && in[n - 2] == '2' &&
      in[n - 1] == '0') {
    cout << "YES" << endl;
    return;
  }

  if (in[n - 1] == '0' && in[0] == '2' && in[1] == '0' && in[2] == '2') {
    cout << "YES" << endl;
    return;
  }

  if (in[n - 1] == '0' && in[n - 2] == '2' && in[n - 3] == '0' &&
      in[n - 4] == '2') {
    cout << "YES" << endl;
    return;
  }
  if (in[0] == '2' && in[1] == '0' && in[n - 1] == '0' && in[n - 2] == '2') {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
  return;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
