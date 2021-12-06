#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
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

vector<ll> fish;

int main() {
  string input;
  cin >> input;
  stringstream check1(input);
  string num;
  while (getline(check1, num, ',')) {
    fish.push_back(stoll(num));
  }

  vector<ll> mp(9);
  for (ll num : fish) {
    mp[num]++;
  }
  for (ll day = 1; day <= 256; day++) {
    vector<ll> temp(9);
    for (ll i = 0; i <= 7; i++) {
      if (i == 0) {
        temp[6] += mp[i];
        temp[8] += mp[i];
      }
      temp[i] += mp[i + 1];
    }
    mp = temp;
  }
  ll sum = 0;
  for (ll num : mp) {
    sum += num;
  };
  cout << sum << endl;
}
