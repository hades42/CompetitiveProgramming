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
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  stack<ll> st;
  vector<ll> left(n);
  vector<ll> right(n);
  for (ll i = 0; i < n; i++) {
    if (st.empty()) {
      left[i] = 0;
      st.push(i);
    } else {
      while (!st.empty() && arr[i] <= arr[st.top()]) {
        st.pop();
      }
      left[i] = st.empty() ? 0 : st.top() + 1;
      st.push(i);
    }
  }
  while (!st.empty()) {
    st.pop();
  }
  for (ll i = n - 1; i >= 0; i--) {
    if (st.empty()) {
      right[i] = n - 1;
      st.push(i);
    } else {
      while (!st.empty() && arr[i] <= arr[st.top()]) {
        st.pop();
      }
      right[i] = st.empty() ? n - 1 : st.top() - 1;
      st.push(i);
    }
  }
  ll mx = 0;
  for (ll i = 0; i < n; i++) {
    mx = max(mx, (right[i] - left[i] + 1) * arr[i]);
  }
  cout << mx << endl;
}
