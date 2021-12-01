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

int main() {
  int N, T;
  cin >> N >> T;
  string rs("0"), tmp; // real state, 1-indexed
  cin >> tmp;
  rs += tmp;
  // cows shaking hooves at time t, 1-indexed time and cows
  vector<int> x(251, 0), y(251, 0);
  for (int t, i = 0; i < T; i++)
    cin >> t >> x[t] >> y[t];
  int np0 = 0, kMin = T, kMax = 0; // nb patient zero ...
  for (int p0 = 1; p0 <= N; p0++) {
    bool pp0 = false; // possible p0
    for (int k = 0; k <= T; k++) {
      string ss(N + 1, '0'); // simulatited state, 1-indexed
      ss[p0] = '1';
      vector<int> ns(N + 1, 0); // nb shakes, 1-indexed
      for (int t = 1; t <= 250; t++)
        if (x[t] > 0) {             // hoove shakes at this t
          int c1 = x[t], c2 = y[t]; // cows shaking
          // infected cows? Test before mofification of ss
          bool ic1 = (ss[c1] == '1'), ic2 = (ss[c2] == '1');
          // infected cow that can infect another one
          if (ic1 && ns[c1] < k) {
            ss[c2] = '1';
            ns[c1]++;
          }
          if (ic2 && ns[c2] < k) {
            ss[c1] = '1';
            ns[c2]++;
          }
        }
      cout << ss << " " << rs << endl;
      if (ss == rs) { // the actuel p0 and k are valid
        pp0 = true;
        kMin = min(kMin, k);
        kMax = max(kMax, k);
      }
    }
    if (pp0)
      np0++;
  }
  cout << np0 << ' ' << kMin << ' ';
  if (kMax == T)
    cout << "Infinity\n";
  else
    cout << kMax << '\n';
}
