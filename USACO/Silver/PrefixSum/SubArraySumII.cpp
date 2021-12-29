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
  ll n, x;
  cin >> n >> x;
  vector<ll> arr(n + 1);
  for (ll i = 1; i <= n; i++) {
    ll num;
    cin >> num;
    arr[i] = arr[i - 1] + num;
  }
  ll res = 0;
  set<ll> st;
  for (ll i = 1; i <= n; i++) {
    if (arr[i] == x) {
      res++;
    } else if (st.count(arr[i] - x)) {
      res++;
    }
    st.insert(arr[i]);
  }
  cout << res << endl;
}
