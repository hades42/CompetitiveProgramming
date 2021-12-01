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
#include <utility>
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
  setIO("mixmilk");
  vector<pr> arr;
  for (ll i = 0; i < 3; i++) {
    ll c, m;
    cin >> c >> m;
    arr.push_back(make_pair(c, m));
  }
  for (ll i = 1; i <= 100; i++) {
    ll currIndex = i % 3;
    ll prevIndex = (currIndex - 1) % 3;
    if (prevIndex < 0)
      prevIndex += 3;

    if (arr[currIndex].first >= arr[prevIndex].second + arr[currIndex].second) {
      arr[currIndex].second = arr[prevIndex].second + arr[currIndex].second;
      arr[prevIndex].second = 0;
    } else {
      arr[prevIndex].second = (arr[prevIndex].second + arr[currIndex].second) -
                              arr[currIndex].first;
      arr[currIndex].second = arr[currIndex].first;
    }
  }
  cout << arr[0].second << endl;
  cout << arr[1].second << endl;
  cout << arr[2].second << endl;
}
