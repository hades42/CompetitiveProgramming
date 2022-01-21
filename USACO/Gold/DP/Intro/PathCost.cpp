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
    setIO("king2");
    vector<vector<ll>> grid(8, vector<ll>(8));
    for(ll i = 0; i < 8; i++){
        for(ll j = 0; j < 8; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> dp(8, vector<ll>(8, INF));
    dp[7][0] = 0;
    for(ll i = 7; i >= 0; i--){
        for(ll j = 0; j < 8; j++){
            // Move up
            if(i + 1 < 8){
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + grid[i][j]);
            }
            // Move right
            if(j - 1 >= 0){
                dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
            }
            // Move diagnal
            if(i+1 < 8 && j - 1 >= 0){
                dp[i][j] = min(dp[i][j], dp[i+1][j-1] + grid[i][j]);
            }
        }
    }
    //print2d(dp);
    cout << dp[0][7] << endl;
}
