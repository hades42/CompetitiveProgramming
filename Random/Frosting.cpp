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
  vector<ll> row(3, 0);
  for (int i = 1; i <= n; i++) {
    ll a;
    cin >> a;
    row[i % 3] += a;
  }

  vector<ll> column(3, 0);
  for (ll i = 1; i <= n; i++) {
    ll b;
    cin >> b;
    column[i % 3] += b;
  }

  ll yellow = row[0] * column[0] + row[1] * column[2] + row[2] * column[1];
  ll pink = row[0] * column[1] + row[1] * column[0] + row[2] * column[2];
  ll white = row[0] * column[2] + row[2] * column[0] + row[1] * column[1];

  // print(row);
  // print(column);
  cout << yellow << " " << pink << " " << white << endl;
}
