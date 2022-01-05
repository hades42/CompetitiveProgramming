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

ll x, y, k, m;
bool visited[101][101][101];
ll ans = INF;

void floodfill(ll currX, ll currY, ll step){
    if(visited[currX][currY][step] || step > k){
        return;
    } 

    ans = min(ans, abs((currX + currY) - m));
    visited[currX][currY][step] = true;
    //case 1;
    floodfill(x, currY, step+1);
    floodfill(currX, y, step+1);
    //case 2
    floodfill(0, currY, step+1);
    floodfill(currX, 0, step+1);
    //case 3
    ll leftX = (currX + currY > y ? (currX + currY) - y : 0);
    ll leftY = (currX + currY > x ? (currX + currY) - x : 0);
    floodfill(leftX, min(y, currX + currY), step+1);
    floodfill(min(x, currX + currY), leftY, step+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("pails");
    cin >> x >> y >> k >> m;

    floodfill(0, 0, 0);
    cout << ans << endl; 
}
