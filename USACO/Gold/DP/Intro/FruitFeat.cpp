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
    setIO("feast");
    ll t, a, b; cin >> t >> a >> b;
    vector<vector<bool>> dp(2, vector<bool>(t+1));
    dp[0][0] = true;
    dp[1][0] = true;
    for(ll i = 1; i <= t; i++){
        if(i - a >= 0){
            dp[0][i] = dp[0][i] | dp[0][i-a];
        }
        if(i - b >= 0){
            dp[0][i] = dp[0][i] | dp[0][i-b];
        }
        dp[1][i / 2] = dp[1][i/2] | dp[0][i];
    } 

    for(ll i = 1; i <= t; i++){
        if(i - a >= 0){
            dp[1][i] = dp[1][i] | dp[1][i-a];
        }
        if(i - b >= 0){
            dp[1][i] = dp[1][i] | dp[1][i-b];
        }
    } 
    for(ll i = t; i >= 1; i--){
        if(dp[1][i]){
            cout << i << endl;
            break;
        }
    }
}
