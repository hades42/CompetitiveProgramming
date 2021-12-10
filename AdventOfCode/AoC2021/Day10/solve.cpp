#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <numeric>
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

vector<string> input;
map<char, ll> point{{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
map<char, ll> point2{{')', 1}, {']', 2}, {'}', 3}, {'>', 4}};
map<char, ll> error;
map<char, char> rev{{'(', ')'}, {'[', ']'}, {'<', '>'}, {'{', '}'}};
int main() {
  string line;
  while (getline(cin, line)) {
    input.push_back(line);
  }
  vector<string> part2;
  for (ll i = 0; i < input.size(); i++) {
    stack<char> st;
    string temp = "";
    bool flag = true;
    for (ll j = 0; j < input[i].size(); j++) {
      char curr = input[i][j];
      if (input[i][j] == '(' || input[i][j] == '[' || input[i][j] == '{' ||
          input[i][j] == '<') {
        st.push(input[i][j]);
      } else if (curr == ')' && st.top() == '(') {
        st.pop();
      } else if (curr == ']' && st.top() == '[') {
        st.pop();
      } else if (curr == '}' && st.top() == '{') {
        st.pop();
      } else if (curr == '>' && st.top() == '<') {
        st.pop();
      } else {
        error[curr]++;
        flag = false;
        break;
      }
    }
    if (flag) {
      while (st.size()) {
        temp += rev[st.top()];
        st.pop();
      }
      part2.push_back(temp);
    }
  }
  ll sum = 0;
  // for (auto po : point) {
  // sum += error[po.first] * point[po.first];
  //}
  // cout << sum << endl;
  vector<ll> ans2;
  for (auto s : part2) {
    ll temp = 0;
    for (ll i = 0; i < s.size(); i++) {
      temp *= 5;
      temp += point2[s[i]];
    }
    ans2.push_back(temp);
  }
  sort(ans2.begin(), ans2.end());
  cout << ans2[ans2.size() / 2] << endl;
}
