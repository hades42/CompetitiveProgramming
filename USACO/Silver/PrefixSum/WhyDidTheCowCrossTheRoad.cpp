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
  setIO("maxcross");
  ll N, K, B;
  cin >> N >> K >> B;
  set<ll> damage;
  for (ll i = 0; i < B; i++) {
    ll num;
    cin >> num;
    damage.insert(num);
  }
  vector<ll> arr(N + 1);
  for (ll i = 1; i <= N; i++) {
    if (damage.count(i)) {
      arr[i] = arr[i - 1];
    } else {
      arr[i] = arr[i - 1] + 1;
    }
  }
  ll mx = 0;
  for (ll i = 0; i <= N - K; i++) {
    mx = max(arr[i + K] - arr[i], mx);
  }
  cout << K - mx << endl;
}
