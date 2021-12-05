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
#include <string>
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

void read_stdin(vector<string> &buffer) {
  string line;
  while (getline(cin, line)) {
    buffer.push_back(line);
  }
}

int main() {
  vector<string> input;
  read_stdin(input);
  vector<vector<ll>> parse;
  ll mxX = 0;
  ll mxY = 0;
  for (ll i = 0; i < input.size(); i++) {
    string curr = input[i];
    vector<ll> token;
    stringstream check1(curr);

    string take;
    while (getline(check1, take, ' ')) {
      token.push_back(stoll(take));
    }
    parse.push_back(token);
  }

  // 0 x1
  // 1 y1
  // 2 x2
  // 3 y2

  for (ll i = 0; i < parse.size(); i++) {
    mxX = max({mxX, parse[i][0], parse[i][2]});
    mxY = max({mxY, parse[i][1], parse[i][3]});
  }
  cout << mxX << " " << mxY << endl;
  vector<vector<ll>> matrix(mxY + 1, vector<ll>(mxX + 1));
  for (ll i = 0; i < parse.size(); i++) {
    ll x1 = parse[i][0];
    ll x2 = parse[i][2];
    ll y1 = parse[i][1];
    ll y2 = parse[i][3];

    // true mean x equal
    // false mean y equal
    bool direct;
    bool exist = false;
    if (x1 == x2) {
      exist = true;
      direct = true;
    } else if (y1 == y2) {
      direct = false;
      exist = true;
    }

    if (exist) {
      if (direct) {
        if (y1 > y2) {
          for (ll j = y2; j <= y1; j++) {
            matrix[j][x1] += 1;
          }
        } else {
          for (ll j = y1; j <= y2; j++) {
            matrix[j][x1] += 1;
          }
        }
      } else {
        if (x1 > x2) {
          for (ll j = x2; j <= x1; j++) {
            matrix[y1][j] += 1;
          }
        } else {
          for (ll j = x1; j <= x2; j++) {
            matrix[y1][j] += 1;
          }
        }
      }
    }
  }

  ll value = 0;
  for (ll i = 0; i < matrix.size(); i++) {
    for (ll j = 0; j < matrix[i].size(); j++) {
      if (matrix[i][j] > 1) {
        value++;
      }
    }
  }
  cout << value << endl;
}
