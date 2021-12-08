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

vector<string> split(string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}

vector<vector<string>> arr;

void getInput() {
  string line;
  while (getline(cin, line)) {
    vector<string> code = split(line, " ");
    arr.push_back(code);
  }
}

int main() {
  getInput();
  set<ll> unique;
  unique.insert(2);
  unique.insert(4);
  unique.insert(3);
  unique.insert(7);
  vector<string> time{"abcefg", "cf",     "acdeg", "acdfg",   "bcdf",
                      "abdfg",  "abdefg", "acf",   "abcdefg", "abcdfg"};
  ll res = 0;
  for (ll i = 0; i < arr.size(); i++) {
    ll temp = 0;
    string check = "abcdefg";
    string get;
    map<char, char> mp;
    do {
      for (ll j = 0; j < check.size(); j++) {
        mp[check[j]] = (char)(j + 97);
      }
      vector<ll> num;
      for (ll j = 0; j <= 9; j++) {
        string curr = arr[i][j];
        for (ll h = 0; h < arr[i][j].size(); h++) {
          curr[h] = mp[curr[h]];
        }
        sort(curr.begin(), curr.end());
        auto it = find(time.begin(), time.end(), curr);
        if (it != time.end()) {
          num.push_back(it - time.begin());
        } else {
          num.push_back(-1);
        }
      }
      sort(num.begin(), num.end());
      bool flag = true;
      for (ll i = 0; i < num.size(); i++) {
        if (num[i] != i) {
          flag = false;
        }
      }
      if (flag) {
        break;
      }
    } while (next_permutation(check.begin(), check.end()));

    for (ll j = 11; j < arr[i].size(); j++) {
      if (arr[i][j].size() == 2) {
        temp *= 10;
        temp += 1;
      } else if (arr[i][j].size() == 4) {
        temp *= 10;
        temp += 4;
      } else if (arr[i][j].size() == 3) {
        temp *= 10;
        temp += 7;
      } else if (arr[i][j].size() == 7) {
        temp *= 10;
        temp += 8;
      } else {
        string curr = arr[i][j];
        for (ll h = 0; h < arr[i][j].size(); h++) {
          curr[h] = mp[curr[h]];
        }
        sort(curr.begin(), curr.end());
        auto it = find(time.begin(), time.end(), curr);
        if (it != time.end()) {
          temp *= 10;
          temp += (it - time.begin());
        }
      }
    }
    res += temp;
  }
  cout << res << endl;
}
