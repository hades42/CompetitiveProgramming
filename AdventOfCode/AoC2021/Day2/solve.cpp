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
void read_stdin(vector<pair<string, ll>> &buffer) {
  string line;
  while (getline(cin, line)) {
    ll i;
    for (i = 0; i < line.size(); i++) {
      if (line[i] == ' ')
        break;
    }
    string first = line.substr(0, i);
    string second = line.substr(i + 1);
    buffer.push_back({first, stoll(second)});
  }
}

int main() {
  vector<pair<string, ll>> arr;
  read_stdin(arr);
  ll hori = 0;
  ll depth = 0;
  ll aim = 0;
  for (ll i = 0; i < arr.size(); i++) {
    if (arr[i].first == "forward") {
      hori += arr[i].second;
      depth += arr[i].second * aim;
    } else if (arr[i].first == "down") {
      aim += arr[i].second;
    } else {
      aim -= arr[i].second;
    }
    cout << hori << " " << depth << " " << aim << endl;
  }
  cout << hori << " " << depth << endl;
  cout << hori * depth << endl;
}
