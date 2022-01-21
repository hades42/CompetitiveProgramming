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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    setIO("ladder");
    ll n; cin >> n;
    vector<ll> stair(n+1);
    for(ll i = 1; i <= n; i++) cin >> stair[i];
    vector<ll> dp(n+1, -INF);
    dp[0] = 0;
    for(ll i = 1; i <= n; i++){
        if(i - 1 >= 0){
            dp[i] = max(dp[i], dp[i-1] + stair[i]);
        }
        if(i - 2 >= 0){
            dp[i] = max(dp[i], dp[i-2] + stair[i]);
        }
    }
    //print(dp);
    cout << dp[n] << endl;
}
