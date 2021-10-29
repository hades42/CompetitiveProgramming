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
  ll floors;
  cin >> floors;
  ll start, goal;
  cin >> start >> goal;
  start--;
  goal--;
  ll up, down;
  cin >> up >> down;

  vector<ll> visited(floors, INF);

  visited[start] = 0;
  queue<ll> q;
  q.push(start);
  while (!q.empty()) {
    ll here = q.front();
    q.pop();

    if (here + up < floors && visited[here] + 1 < visited[here + up]) {
      visited[here + up] = visited[here] + 1;
      q.push(here + up);
    }
    if (here - down >= 0 && visited[here] + 1 < visited[here - down]) {
      visited[here - down] = visited[here] + 1;
      q.push(here - down);
    }
  }

  if (visited[goal] == INF) {
    cout << "use the stairs" << endl;
    return 0;
  }
  cout << visited[goal] << endl;
  print(visited);
}
