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

bool isRotation(string s1, string s2) {
  string wholeString = s1 + s1;
  vector<int> patternTable(s2.size(), 0);
  int i = 1, j = 0;
  patternTable[0] = 0;
  while (i < s2.size()) {
    if (s2[i] == s2[j]) {
      patternTable[i] = j + 1;
      i++;
      j++;
    } else {
      if (j > 0) {
        j = patternTable[j - 1];
      } else {
        patternTable[i] = 0;
        i++;
      }
    }
  }
  int n = wholeString.size();
  int m = s2.size();
  i = j = 0;
  while (i < n) {
    if (wholeString[i] == s2[j]) {
      if (j == m - 1)
        return true;
      i++;
      j++;
    } else {
      if (j > 0) {
        j = patternTable[j - 1];
      } else {
        i++;
      }
    }
  }
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s1, s2;
  cin >> s1 >> s2;
  bool isIt = isRotation(s1, s2);
  cout << isIt << endl;
}
