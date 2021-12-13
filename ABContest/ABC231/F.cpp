#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <numeric>
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

bool comp(pr a, pr b) { return a.second < b.second; }

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n;
  cin >> n;
  vector<ll> A(n);
  vector<ll> B(n);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }

  for (ll i = 0; i < n; i++) {
    cin >> B[i];
  }

  vector<pr> arr(n);
  for (ll i = 0; i < n; i++) {
    arr[i] = {A[i], B[i]};
  }
  sort(arr.begin(), arr.end());
  for (ll i = 1; i <= n; i++) {
    arr[i - 1].first = i;
  }
  sort(arr.begin(), arr.end(), comp);
  for (ll i = 1; i <= n; i++) {
    arr[i - 1].second = i;
  }

  ll res = 0;
  for (ll i = 0; i < arr.size(); i++) {
    res += min(arr[i].first - 1, n - arr[i].second);
    res += 1;
  }
  cout << res << endl;
}
