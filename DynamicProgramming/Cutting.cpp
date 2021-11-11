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
  ll n, B;
  cin >> n >> B;
  vector<ll> arr(n);
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll even = 0;
  ll odd = 0;
  if (arr[0] % 2 == 0) {
    even++;
  } else {
    odd++;
  }
  vector<ll> value;
  for (ll i = 1; i < n; i++) {
    if (arr[i] % 2 == 0) {
      even++;
    } else {
      odd++;
    }
    if (even == odd && i < n - 1) {
      value.push_back(abs(arr[i + 1] - arr[i]));
    }
  }
  sort(value.begin(), value.end());
  ll res = 0;
  for (ll i = 0; i < value.size(); i++) {
    B -= value[i];
    if (B >= 0) {
      res++;
    } else
      break;
  }
  cout << res << endl;
}
