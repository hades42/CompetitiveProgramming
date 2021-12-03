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
void read_stdin(vector<string> &buffer) {
  string line;
  while (getline(cin, line)) {
    buffer.push_back(line);
  }
}

int binaryToDecimal(string n) {
  string num = n;
  int dec_value = 0;

  // Initializing base value to 1, i.e 2^0
  int base = 1;

  int len = num.length();
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == '1')
      dec_value += base;
    base = base * 2;
  }

  return dec_value;
}

int main() {
  vector<string> input;
  read_stdin(input);
  ll size = input[0].size();
  string gama = "";
  string epli = "";
  vector<string> oxy = input;
  vector<string> co2 = input;

  for (ll i = 0; i < size; i++) {
    ll bit1 = 0;
    ll bit0 = 0;

    ll co21 = 0;
    ll co20 = 0;

    for (ll j = 0; j < oxy.size(); j++) {
      if (oxy[j][i] == '0') {
        bit0++;
      } else {
        bit1++;
      }
    }

    for (ll j = 0; j < co2.size(); j++) {
      if (co2[j][i] == '0') {
        co20++;
      } else {
        co21++;
      }
    }
    vector<string> tempOxy;
    vector<string> tempco2;
    for (ll j = 0; j < oxy.size(); j++) {
      if (bit0 > bit1) {
        if (oxy[j][i] == '0') {
          tempOxy.push_back(oxy[j]);
        }
      } else if (bit1 > bit0) {
        if (oxy[j][i] == '1') {
          tempOxy.push_back(oxy[j]);
        }
      } else {
        if (oxy[j][i] == '1') {
          tempOxy.push_back(oxy[j]);
        }
      }
    }

    for (ll j = 0; j < co2.size(); j++) {
      if (co20 > co21) {
        if (co2[j][i] == '1') {
          tempco2.push_back(co2[j]);
        }
      } else if (co21 > co20) {
        if (co2[j][i] == '0') {
          tempco2.push_back(co2[j]);
        }
      } else {
        if (co2[j][i] == '0') {
          tempco2.push_back(co2[j]);
        }
      }
    }

    if (oxy.size() > 1) {
      oxy = tempOxy;
    }
    if (co2.size() > 1) {
      co2 = tempco2;
    }
  }
  cout << binaryToDecimal(co2[0]) * binaryToDecimal(oxy[0]) << endl;
}
