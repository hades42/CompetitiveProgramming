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

ll sum(ll num) {
  ll ans = 0;
  while (num > 0) {
    ans += (num % 10);
    num /= 10;
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n;
  cin >> n;
  ll curr = 0;
  while (n) {
    curr++;
    if (sum(curr) == 10)
      n--;
  }
  cout << curr << endl;
}
