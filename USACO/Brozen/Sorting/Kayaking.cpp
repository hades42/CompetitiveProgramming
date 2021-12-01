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
  ll n;
  cin >> n;
  ll N = 2 * n;
  vector<ll> arr(N);
  for (ll i = 0; i < N; i++) {
    cin >> arr[i];
  }
  ll res = INF;
  sort(arr.begin(), arr.end());
  for (ll i = 0; i < N; i++) {
    for (ll j = i + 1; j < N; j++) {
      vector<ll> temp;
      for (ll k = 0; k < N; k++) {
        if (k == i || k == j)
          continue;
        temp.push_back(arr[k]);
      }
      ll sum = 0;
      // print(temp);
      for (ll k = 0; k < temp.size(); k += 2) {
        sum += abs(temp[k] - temp[k + 1]);
      }
      res = min(res, sum);
    }
  }
  cout << res << endl;
}
