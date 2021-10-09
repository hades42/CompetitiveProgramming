#include <algorithm>
#include <array>
#include <cstdlib>
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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  string line;
  getline(cin, line);
  ll init;
  istringstream iss(line);
  set<ll> check;
  ll count = 0;
  do {
    string subs;
    iss >> subs;
    if (count == 0) {
      init = subs[0] - '0';
    } else {
      char condition = subs[0];
      ll value = subs[1] - '0';
    }

    count++;
  } while (iss);
  // while (cin >> step) {
  // if (step.empty())
  // break;
  // char condition = step[0];
  // ll value = step[1] - '0';
  // if (condition == 'D') {
  // init -= value;
  // if (init <= 0) {
  // cout << "illegal" << endl;
  // return 0;
  //}
  // if (check.count(init)) {
  // cout << "illegal" << endl;
  // return 0;
  //}
  // check.insert(init);
  //} else {
  // init += value;
  // if (init > 20) {
  // cout << "illegal" << endl;
  // return 0;
  //}
  // if (check.count(init)) {
  // cout << "illegal" << endl;
  // return 0;
  //}
  // check.insert(init);
  //}
  //}
  // for (int i = 1; i <= 20; i++) {
  // if (!check.count(i)) {
  // cout << i << " ";
  //}
  //}
  // cout << endl;
}
