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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  set<char> vowel;
  vowel.insert('A');
  vowel.insert('E');
  vowel.insert('I');
  vowel.insert('O');
  vowel.insert('U');
  string in;
  cin >> in;
  bool novowel = true;
  if (vowel.count(in[0])) {
    cout << "no" << endl;
    return 0;
  }
  for (ll i = 1; i < (ll)in.size(); i++) {
    char curr = in[i];
    if (vowel.count(curr)) {
      novowel = false;
      if (in[i - 1] == 'G') {
        continue;
      } else if (in[i - 1] == 'L') {
        continue;
      } else {
        cout << "no" << endl;
        return 0;
      }
    }
  }
  if (novowel) {
    cout << "no" << endl;
    return 0;
  }
  cout << "yes" << endl;
  return 0;
}
