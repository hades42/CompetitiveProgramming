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
void read_stdin(vector<ll> &buffer) {
  string line;
  while (getline(cin, line)) {
    buffer.push_back(stoll(line));
  }
}

int main() {
  vector<ll> arr;
  read_stdin(arr);
  vector<ll> sum;
  for (ll i = 0; i < arr.size() - 2; i++) {
    ll temp = 0;
    for (ll j = 0; j < 3; j++) {
      temp += arr[i + j];
    }
    sum.push_back(temp);
  }
  ll res = 0;
  for (ll i = 1; i < sum.size(); i++) {
    if (sum[i] > sum[i - 1]) {
      res++;
    }
  }
  cout << res << endl;
}
