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
    ll n; cin >> n;
    if(n == 0){
        cout << 1 << endl;
        return 0;
    }
    vector<vector<ll>> dp(3, vector<ll>(n));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][0] = 1;

    for(ll i = 1; i < n; i++){
        // If we start at 'a' first
        dp[0][i] = dp[0][i-1] + dp[1][i-1] + dp[2][i-1];

        // If we start at 'b' first
        dp[1][i] = dp[1][i-1] + dp[2][i-1];

        // If we start at 'c' first
        dp[2][i] = dp[0][i-1] + dp[1][i-1] + dp[2][i-1];
    }

    //print2d(dp);
    cout << dp[0][n-1] + dp[1][n-1] + dp[2][n-1] << endl;
}
