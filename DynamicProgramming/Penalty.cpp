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

void solve() {
  string s;
  cin >> s;
  ll ques = 0;
  ll one = 0;
  ll zero = 0;
  for (ll i = 0; i < s.size(); i++) {
    if (s[i] == '?') {
      ques++;
    }
    if (s[i] == '1')
      one++;
    if (s[i] == '0')
      zero++;
  }

  if (one == 10 || zero == 10) {
    cout << 10 << endl;
    return;
  }

  vector<char> arr(ques);
  ll res = 10;
  if (ques > 0) {
    for (ll mask = 0; mask < (1 << ques); mask++) {
      for (ll i = 0; i < ques; i++) {
        if (mask & (1 << i)) {
          arr[i] = '1';
        } else {
          arr[i] = '0';
        }
      }
      // print(arr);
      string temp = s;
      ll j = 0;
      for (ll z = 0; z < s.size(); z++) {
        if (temp[z] == '?') {
          temp[z] = arr[j];
          j++;
        }
      }

      ll A = 0;
      ll B = 0;
      for (ll i = 0; i < 10; i++) {
        if (i % 2 == 0) {
          if (temp[i] == '1')
            A++;
        } else {
          if (temp[i] == '1')
            B++;
        }
        if (A > B + (10 - i) / 2) {
          res = min(res, i + 1);
          break;
        }
        if (B > A + (9 - i) / 2) {
          res = min(res, i + 1);
          break;
        }
      }
    }
  } else {
    ll A = 0;
    ll B = 0;
    for (ll i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        if (s[i] == '1')
          A++;
      } else {
        if (s[i] == '1')
          B++;
      }
      if (A > B + (10 - i) / 2) {
        res = min(res, i + 1);
        break;
      }
      if (B > A + (9 - i) / 2) {
        res = min(res, i + 1);
        break;
      }
    }
  }
  cout << res << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
