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

int main() {
  double n;
  cin >> n;
  vector<double> arr(n);
  double sum = 0;
  for (double i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  double target = sum / n;
  map<double, double> mp;
  double res = 0;
  for (double i = 0; i < n; i++) {
    arr[i] -= target;
  }
  vector<double> prefix(n + 1);
  mp[0] = 1;
  for (double i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + arr[i - 1];
    mp[prefix[i]]++;
  }
  for (auto pi : mp) {
    cout << pi.first << " " << pi.second << endl;
    res += (pi.second - 1) * pi.second / 2;
  }
  cout << res << endl;
}
