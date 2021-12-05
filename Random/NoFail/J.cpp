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

int dictionaryContains(string word, vector<string> dict) {
  for (int i = 0; i < dict.size(); i++)
    if (dict[i].compare(word) == 0)
      return true;
  return false;
}

// returns true if string can be segmented into space
// separated words, otherwise returns false
bool wordBreak(string str, vector<string> dict) {
  int n = str.size();
  if (n == 0)
    return true;

  // Create the DP table to store results of subroblems.
  // The value dp[i] will be true if str[0..i] can be
  // segmented into dictionary words, otherwise false.
  vector<bool> dp(n + 1, 0); // Initialize all values
  // as false.

  // matched_index array represents the indexes for which
  // dp[i] is true. Initially only -1 element is present
  // in this array.
  vector<int> matched_index;
  matched_index.push_back(-1);

  for (int i = 0; i < n; i++) {
    int msize = matched_index.size();

    // Flag value which tells that a substring matches
    // with given words or not.
    int f = 0;

    // Check all the substring from the indexes matched
    // earlier. If any of that substring matches than
    // make flag value = 1;
    for (int j = msize - 1; j >= 0; j--) {

      // sb is substring starting from
      // matched_index[j]
      // + 1  and of length i - matched_index[j]
      string sb = str.substr(matched_index[j] + 1, i - matched_index[j]);

      if (dictionaryContains(sb, dict)) {
        f = 1;
        break;
      }
    }

    // If substring matches than do dp[i] = 1 and
    // push that index in matched_index array.
    if (f == 1) {
      dp[i] = 1;
      matched_index.push_back(i);
    }
  }
  return dp[n - 1];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  string in;
  cin >> in;
  ll n;
  cin >> n;
  vector<string> dict;
  for (ll i = 0; i < n; i++) {
    string s;
    cin >> s;
    dict.push_back(s);
  }
  if (wordBreak(in, dict)) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }
}
