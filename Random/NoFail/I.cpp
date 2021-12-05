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

ll binarySearch(ll target, ll start, ll &len, vector<ll> &nums) {
  ll l = start, r = len, mid;
  while (l < r) {
    mid = (l + r) / 2;
    if (nums[mid] < target) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}

ll triangleNumber(vector<ll> &nums) {
  sort(begin(nums), end(nums));
  ll count = 0, len = nums.size(), wanted;
  for (ll i = 0; i < len - 2; i++) {
    for (ll j = i + 1; j < len - 1; j++) {
      wanted = nums[i] + nums[j];
      ll index = binarySearch(wanted, j + 1, len, nums);
      if (index != -1) {
        count += index - 1 - j;
      }
    }
  }
  return count;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll res = triangleNumber(arr);
  cout << res << endl;
}
