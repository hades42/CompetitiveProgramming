#include <bits/stdc++.h>
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
#define MAX_N 100000

int N, S[MAX_N];

int round3(double x) { return (int)(1000.0 * x + 0.5); }

int possible(double guess)
{
  int i, total=0;
  double best, current;
  for (i=0; i<N; i++) total += S[i];
  best = current = S[1] - guess;
  for (i=2; i<N-1; i++) {
    if (current < 0) current = 0;
    current += S[i] - guess;
    if (current > best) best = current;
  }
  return best >= total - guess * N;
}

double solve(void)
{
  double low = 1.0, high = MAX_N * 10000.0;
  while (round3(low) != round3(high)) 
    if (possible((low+high)/2)) high = (low+high)/2;
    else low = (low+high)/2;
  return low;
}

int main(void)
{
  int i;
  //setIO()
  scanf ("%d", &N);
  for (i=0; i<N; i++) scanf ("%d", &S[i]);
  printf ("%.3lf\n", solve());
  return 0;
}
