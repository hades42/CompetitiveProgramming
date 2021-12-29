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
ll n, x, y; 

bool good(ll time){
    // We minus for min(x, y) because we gonna take this min(x,y) time to try to produce the first copy
    time -= min(x, y);
    if(time < 0) return false;
    // We +1 for the copy we take time to produce above
    ll sum = (time / x) + (time / y) + 1;
    return sum >= n;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> x >> y;
    ll left = 0;
    ll right = 1;
    while(!good(right)) right *= 2;

    while(left + 1 < right){
        ll mid = (left + right) /2; 
        if(good(mid)){
            right = mid;
        } else{
            left = mid;
        }
    }

    cout << right << endl;
}
