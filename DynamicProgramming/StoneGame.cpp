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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    ll maxPos = max_element(arr.begin(), arr.end()) - arr.begin();
    ll minPost = min_element(arr.begin(), arr.end()) - arr.begin();

    ll res = min({max(maxPos, minPost) + 1, (n - 1) - min(maxPos, minPost) + 1,
                  maxPos + 1 + (n - 1) - minPost + 1,
                  minPost + 1 + (n - 1) - maxPos + 1});
    cout << res << endl;
  }
}
