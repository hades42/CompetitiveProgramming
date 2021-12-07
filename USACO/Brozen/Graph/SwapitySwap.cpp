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
  setIO("swap");
  ll n, k, a1, a2, b1, b2;
  cin >> n >> k >> a1 >> a2 >> b1 >> b2;
  vector<ll> arr(n + 1);
  for (ll i = 1; i <= n; i++) {
    arr[i] = i;
  }

  ll remain = 0;
  vector<ll> temp = arr;
  for (ll i = 1; i <= k; i++) {
    reverse(temp.begin() + a1, temp.begin() + a2 + 1);
    reverse(temp.begin() + b1, temp.begin() + b2 + 1);

    // There is a cycle here
    if (temp == arr) {
      remain = k % i;
      break;
    }
  }

  while (remain) {
    reverse(temp.begin() + a1, temp.begin() + a2 + 1);
    reverse(temp.begin() + b1, temp.begin() + b2 + 1);
    remain--;
  }

  for (ll i = 1; i <= n; i++) {
    cout << temp[i] << endl;
  }
}
