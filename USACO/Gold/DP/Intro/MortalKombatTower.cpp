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

void solve(){
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    if(n == 1){
        cout << arr[0] << endl;
        return;
    }
    //0 is friends
    //1 is you 
    vector<vector<ll>> dp(2, vector<ll>(n));
    dp[0][0] = arr[0];
    dp[1][0] = INF;

    dp[0][1] = arr[0] + arr[1];
    dp[1][1] = arr[0];

    for(ll i = 2; i < n; i++){
        // If this is friend turn so previous move would be your turn
        dp[0][i] = min(dp[1][i-1] + arr[i], dp[1][i-2] + arr[i] + arr[i-1]);
        // If this is your turn, so previous move would be friend turn
        dp[1][i] = min(dp[0][i-1], dp[0][i-2]);
    }
    cout << min(dp[0][n-1], dp[1][n-1]) << endl;
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll t; cin >> t;
    while(t--){
        solve();
    }
}
